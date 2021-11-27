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
				if(cmd2=="onto"){ //�b�Na�h��b�W���e�A���Na�Mb�W���n���^��Ӫ���m
					recover_block(b);
					put_block(a,b);
				}
				else{ //over �b�Na�h��b�Ҧb������n�줧�W���e�A���Na�W���n���^��Ӫ����_�]b�Ҧb������n�줣�ʡ^
					put_block(a,b);
				}
			}
			else if(cmd1=="pile"){
				if(cmd2=="onto"){ //�Na�����M��W���n��@�_���b�W�A�b�h���eb�W�誺�n���^���
					recover_block(b);
					put_block(a,b);
				}
				else{ //�Na�����M��W���n��@�_�h���b�Ҧb������n�줧�W
					put_block(a,b);
				}
			}
		}
	}
	
	return 0;
}
