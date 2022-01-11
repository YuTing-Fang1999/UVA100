## 101 - The Blocks Problem
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=37
* move a onto b
在將a搬到b上之前，先將a和b上的積木放回原來的位置（例如：1就放回1的最開始位罝）
* move a over b
在將a搬到b所在的那堆積木之上之前，先將a上的積木放回原來的位罝（b所在的那堆積木不動）
* pile a onto b
將a本身和其上的積木一起放到b上，在搬之前b上方的積木放回原位
* pile a over b
將a本身和其上的積木一起搬到到b所在的那堆積木之上
* quit
動作結束
* 前四個動作中若a=b，或者a, b在同一堆積木中，那麼這樣的動作算是不合法的。所有不合法的動作應該被忽略，也就是對各積木均無改變。
### 使用vector(加強版的陣列)
### 函數設計
* 判定是否在同一堆積木或a=b
* 將a上面的積木放回去
* 將a上面的積木(包含a)移到b上
* print_blocks、清空block

這題寫超久==
腦袋要清楚，定好函式，有些功能可以合一(放一個=先將上面放回去再移)
要善用vector

```cpp=
#include <iostream>
#include <vector>
#include <string>

using namespace std ;

vector<int> blocks[25];
int curBlockPos[25];

bool is_same_block(int a,int b){
	return a==b || curBlockPos[a]==curBlockPos[b];
}

void recover_block(int a){
	int a_pos = curBlockPos[a];
	int a_index;
	bool find_a = false;
	int mark;
	for(int i=0;i<blocks[a_pos].size();++i){
		if(find_a){
			mark = blocks[a_pos][i];
			blocks[mark].push_back(mark);
			curBlockPos[mark] = mark;
		}
		else if(blocks[a_pos][i] == a){
			a_index = i;
			find_a = true;
		}
	}
	
	blocks[a_pos].erase(blocks[a_pos].begin() + a_index + 1, blocks[a_pos].end());
}

void put_block(int a, int b){
	int a_pos = curBlockPos[a];
	int b_pos = curBlockPos[b];
	int a_index;
	bool find_a = false;
	for(int i=0;i<blocks[a_pos].size();++i){
		if(find_a){
			blocks[b_pos].push_back(blocks[a_pos][i]);
			curBlockPos[blocks[a_pos][i]] = b_pos;
		}
		else if(blocks[a_pos][i] == a){
			blocks[b_pos].push_back(blocks[a_pos][i]);
			curBlockPos[blocks[a_pos][i]] = b_pos;
			a_index = i;
			find_a = true;
		}
	}
	
	blocks[a_pos].erase(blocks[a_pos].begin() + a_index, blocks[a_pos].end());
}

void print_blocks(int n){
	for(int i = 0 ; i < n; ++i)
    {
        cout << i << ":";
        for(int j = 0 ; j < blocks[i].size(); ++j)
        {
            cout << " " << blocks[i][j];
        }
        cout << endl;
        blocks[i].clear();
//        cout << "cur position = " << curBlockPos[i] << endl;
		
    }

//    cout << endl;
	
}

int main(){
	int n;
	string cmd1;
	string cmd2;
	int a,b;
	
	while(cin>>n){
		//init box
		for(int i=0;i<n;++i){
			blocks[i].push_back(i);
			curBlockPos[i]=i;
		}
		
		//input cmd
		while(cin>>cmd1){
			if( cmd1 == "quit" ) {
				print_blocks(n);
				break;
			}
			cin>>a>>cmd2>>b;
			
			if (is_same_block(a,b)) continue;
			
			if(cmd1=="move"){
				recover_block(a);
				if(cmd2=="onto"){ //在將a搬到b上之前，先將a和b上的積木放回原來的位置
					recover_block(b);
					put_block(a,b);
				}
				else{ //over 在將a搬到b所在的那堆積木之上之前，先將a上的積木放回原來的位罝（b所在的那堆積木不動）
					put_block(a,b);
				}
			}
			else if(cmd1=="pile"){
				if(cmd2=="onto"){ //將a本身和其上的積木一起放到b上，在搬之前b上方的積木放回原位
					recover_block(b);
					put_block(a,b);
				}
				else{ //將a本身和其上的積木一起搬到到b所在的那堆積木之上
					put_block(a,b);
				}
			}
		}
	}
	
	return 0;
}
```
