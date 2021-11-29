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
		if(a.dim[i] < b.dim[i]) return true; //�洫 
	}
	return true;
}

//a�O�_�i�]�bb�� 
bool is_contain(Box &a, Box &b){
	for(int i=0;i<a.dim.size();++i){
		if(a.dim[i] >= b.dim[i]) return false; //����]����!!!�ڰڰڭ��bug�b�o�� 
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
			sort(b.dim.begin(),b.dim.end()); //�w�]�Ѥp�ƨ�j 
			boxes.push_back(b);
		}
		sort(boxes.begin(),boxes.end(),box_compare);
		
		//�ˬd�O�_�Ƨǥ��T 
//		for(int i=0;i<boxes.size();++i){
//			cout<<i<<"   ";
//			for(int j=0;j<n;++j){
//				cout<<boxes[i].dim[j]<<" ";
//			}
//			cout<<endl;
//		}
		
		//��X�̪��ǦC
		vector<int> boxMaxLen(k,1), preBox(k,-1);
		int maxLen = 1, lastBox = 0; //�W��bug!����]��-1!!���M���Ǵ���print���X�� 
		for(int i=0;i<k;++i){
			for(int j=i+1;j<k;++j){
				if(is_contain(boxes[i],boxes[j])){//�p�Gi�i�Q�]�bj�� 
//					cout<<i<<"�i�Q�]�b"<<j<<"��"<<endl; 
					if(boxMaxLen[i]+1 > boxMaxLen[j]){//�p�Gj�]��i������ܪ��N��s 
//						cout<<"��s"<<j<<"������"<<endl; 
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
		print_ans(boxes, preBox, lastBox); //�Q�λ��j�����X���� 
		cout<<endl;

		boxes.clear();
	}
}
