//103 - Stacking Boxes

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Box{
	int id;
	vector<int> dim;
	Box(int i,int n){
		id = i;
		dim = vector<int>(n,0);
	}
};
                 //i+1     //i 
bool box_compare(Box &a, Box &b){
	for(int i=0;i<a.dim.size();++i){
		if(a.dim[i] > b.dim[i]) return false;
		if(a.dim[i] < b.dim[i]) return true; //交換 
	}
	return true;
}

//a是否可包在b裡 
bool is_contain(Box &a, Box &b){
	for(int i=0;i<a.dim.size();++i){
		if(a.dim[i] >= b.dim[i]) return false; //等於也不行!!!啊啊啊原來bug在這裡 
	}
	return true;
}

void print_ans(vector<Box> &boxes, vector<int> &preBox, int lastBox){
	if(lastBox==-1) return;
	print_ans(boxes, preBox, preBox[lastBox]);
	cout<<boxes[lastBox].id<<" ";
}

int main(){
	int k,n;
	vector<Box> boxes;
	while(cin>>k>>n){
		
		for(int i=0;i<k;i++){
			Box b(i+1,n);
			for(int j=0;j<n;++j){
				cin>>b.dim[j];
			}
			sort(b.dim.begin(),b.dim.end()); //預設由小排到大 
			boxes.push_back(b);
		}
		sort(boxes.begin(),boxes.end(),box_compare);
		
		//檢查是否排序正確 
//		for(int i=0;i<boxes.size();++i){
//			cout<<i<<"   ";
//			for(int j=0;j<n;++j){
//				cout<<boxes[i].dim[j]<<" ";
//			}
//			cout<<endl;
//		}
		
		//找出最長序列
		vector<int> boxMaxLen(k,1), preBox(k,-1);
		int maxLen = 1, lastBox = 0; //超級bug!不能設為-1!!不然有些測資print不出來 
		for(int i=0;i<k;++i){
			for(int j=i+1;j<k;++j){
				if(is_contain(boxes[i],boxes[j])){//如果i可被包在j裡 
//					cout<<i<<"可被包在"<<j<<"裡"<<endl; 
					if(boxMaxLen[i]+1 > boxMaxLen[j]){//如果j包住i後長度變長就更新 
//						cout<<"更新"<<j<<"的長度"<<endl; 
						boxMaxLen[j]=boxMaxLen[i]+1;
						preBox[j] = i;
						if(boxMaxLen[j] > maxLen){
							maxLen = boxMaxLen[j];
							lastBox = j;
						}
					}
					
				}
			}
		}
		
		cout<<maxLen<<endl;
		print_ans(boxes, preBox, lastBox); //利用遞迴反轉輸出順序 
		cout<<endl;

		boxes.clear();
	}
}
