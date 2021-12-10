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
	    //砞﹚т程絛瞅
	    for(int i = totalPancakes-1 ; i > 0  ; --i ){  
	    	int indexOfMax = 0;
	    	//т絛瞅ず程
	    	for(int j=0;j<=i;++j){
	    		if(pancakes[indexOfMax] < pancakes[j])  indexOfMax=j;
			}
			
			//indexOfMax ぃ程娩 
			if(indexOfMax < i){ 
				//flip indexOfMax to 程オ娩 
				if(indexOfMax != 0){
					flip(pancakes, totalPancakes, indexOfMax);
				}
				//flip indexOfMax to 程娩 
				flip(pancakes, totalPancakes, i);
			}
		}
		
		printf("0\n");
	}
}
