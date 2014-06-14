#include<iostream>
using namespace std;

long swapPosition(long x, int i,int j){
	if(((x>>i)&1)!=((x>>j)&1)){
		x ^= ((1l<<i) | (1l<<j));
	}
	return x;
}

int main(){
	cout<<swapPosition(42,2,3)<<endl;
	cout<<swapPosition(10,1,2)<<endl;
}