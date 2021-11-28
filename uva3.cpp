#include <iostream>
#define B 0
#define G 1
#define C 2

using namespace std;
int arr[9];
int colorSet[6][3] = {
	{B,C,G},
	{B,G,C},
	{C,B,G},
	{C,G,B},
	{G,B,C},
	{G,C,B}
};

int bottle_sum(){
	int sum=0;
	for(int i=0;i<9;++i) sum+=arr[i];
	return sum;
}

int reserve_num(int b1, int b2, int b3){
	int num = 0;
	num+=arr[b1];
	num+=arr[3+b2];
	num+=arr[6+b3];
	return num;
}

void print_ans(int mark, int num){
	switch(mark){
		case 0:
			cout<<"BCG ";
			break;
		case 1:
			cout<<"BGC ";
			break;
		case 2:
			cout<<"CBG ";
			break;
		case 3:
			cout<<"CGB ";
			break;
		case 4:
			cout<<"GBC ";
			break;
		case 5:
			cout<<"GCB ";
			break;
	}
	cout<<num<<endl;	
}

int main(){
	int sum, curNum, mark, num;
	while(cin>>arr[0]){
		for(int i=1;i<9;++i){
			cin>>arr[i];
		}
		//�p�����bottle���ƶq 
		sum = bottle_sum();
		
		//��O�d�~�l�ƶq�̦h���ƦC (�N��ݷh�����~�l�̤�) 
		curNum=0; mark=0; num=0;
		for(int i=0;i<6;++i){
			num = reserve_num(colorSet[i][0],colorSet[i][1],colorSet[i][2]);
			if(num>curNum){
				curNum=num;
				mark=i;
			}
		}
		
		//�h���ƶq = �����~�l - �O�d�ƶq 
		print_ans(mark,sum-curNum);
		
	}
	
	return 0;
} 
