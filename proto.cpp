#include <iostream>
using namespace std;

int GCD(int x, int y){
	if(x==0){
		return y;
	}else if(y==0){
		return x;
	}else if(!(x&1)&&!(y&1)){
		return GCD(x>>1,y>>1)<<1;
	}else if(!(x&1)&&(y&1)){
		return GCD(x>>1,y);
	}else if((x&1)&&!(y&1)){
		return GCD(x,y>>1);
	}else if(x>y){
		return GCD(x-y,y);
	}else{
		return GCD(x,y-x);
	}
}

int main(){
	cout<<GCD(10,5);
}