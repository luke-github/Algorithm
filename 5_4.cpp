#include <iostream>
using namespace std;

unsigned long minimal_bits(unsigned long x){
	for(int i=0;i<63;i++){
		if((x>>i)&1^((x>>(i+1))&1)){
			x ^= 1<<i | i<<(i+1);
			return x;
		}
	}
	throw invalid_argument("cannot find correct answers");
}

int main(){
	cout<<minimal_bits(3);
}