#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;


void flip( int pancakes[], int totalPancakes, int index ){
  for( int i = 0 ; i <= index / 2 ; ++i ){
    swap( pancakes[i], pancakes[index-i] );
  }
  printf("%d ",totalPancakes - index);
}

int main(){
	string input_str;
	while(getline(cin,input_str)){
		cout<<input_str<<endl;
		stringstream ss(input_str);
		
		//init
		int pancakes[35] = {0};
	    int totalPancakes = 0;
	    while( ss >> pancakes[totalPancakes] ){
	      ++totalPancakes;
	    }
	    
	    //start compute	
	    int indexOfMax = 0;
	    //�]�w��̤j�Ȫ��d��
	    for(int i = totalPancakes-1 ; i > 0  ; --i ){  
	    	int indexOfMax = 0;
	    	//�䦹�d�򤺪��̤j��
	    	for(int j=0;j<=i;++j){
	    		if(pancakes[indexOfMax] < pancakes[j])  indexOfMax=j;
			}
			
			//indexOfMax ���b�̥k�� 
			if(indexOfMax < i){ 
				//flip indexOfMax to �̥��� 
				if(indexOfMax != 0){
					flip(pancakes, totalPancakes, indexOfMax);
				}
				//flip indexOfMax to �̥k�� 
				flip(pancakes, totalPancakes, i);
			}
		}
		
		printf("0\n");
	}
}
