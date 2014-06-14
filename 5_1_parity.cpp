#include<iostream>
using namespace std;

int checkParity(int n){
	int result = 0;
	while(n){
		result ^= (1&n);
		n >>= 1;
	}
	return result;
}

// some performance improvement in this function
int checkParity2(int n){
	int result = 0;
	while(n){
		result ^= 1;
		n &= (n-1);
	}
	return result;
}

int main(){
	int testnum = 5;
	cout<<checkParity(testnum)<<endl;
	cout<<checkParity2(testnum)<<endl;
}