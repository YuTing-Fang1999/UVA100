#include<iostream>
#include<cmath>
using namespace std;

int main(){
  double n, p;
  while( cin>>n>>p )
  	//converting to %.0lf, it's rounded to the nearest integer.
    printf( "%.0lf\n", pow( p, 1.0/n ) );
  return 0;
}
