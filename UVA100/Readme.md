## 100 - The 3n + 1 problem
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=36

### 最直接的思路->直接計算
* 題目並沒有指定 i , j 哪個比較大
* 印出的ij順序要跟輸入的ij順序一樣
```cpp=
#include <stdio.h>
#include <iostream>
using namespace std;

int cycle_len(int n);
int max_cycle_len(int n1, int n2);

int main(){
	int n1,n2,max;
	while(cin >> n1){
		cin >> n2;
		if(n1<n2){
			max = max_cycle_len(n1, n2);
		}else{
			max = max_cycle_len(n2, n1);
		}
		
//		printf("%d \n",max);
		
		cout << n1 << " " << n2;
   		cout << " " << max << endl;
	}
	return 0;
}
int max_cycle_len(int n1, int n2){
	int max_len=0,new_len=0;
	for(int i=n1;i<=n2;++i){		
		new_len = cycle_len(i);
		if( new_len > max_len) max_len = new_len;
	}
	return max_len;
}

int cycle_len(int n){
	int count=0;
	while(1){
		count++;
//		printf("%d\n",n);
		if (n==1) break;
		if(n%2==1) n=3*n+1;
		else n=n/2;
	}
	return count;
}
```
```cpp=
if(n%2==1) //runtime = 0.4
```
要改成下面這樣比較快
```cpp=
if(n%2)   //runtime = 0.32
```
判斷式直接寫在while裡面
```cpp=
int count=1;
while(n!=1){ //runtime = 0.31
    count++;
    ...
}
```
