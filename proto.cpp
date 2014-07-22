#include <iostream>
using namespace std;

unsigned add_algorithm(unsigned a, unsigned b){
	unsigned sum=0,temp_a=a,temp_b=b,k=1,carryin=0;
	while(temp_a||temp_b){
		unsigned ak=a&k, bk=b&k;
		unsigned carryout = (ak&bk) | (ak&carryin) | (bk&carryin);
		sum |= ak^bk^carryin;
		carryin = carryout<<1;
		k<<=1;
		temp_a>>=1;
		temp_b>>=1;
	}
	return sum|carryin;
}

unsigned multiple_algorithm(unsigned x, unsigned y){
	unsigned sum = 0;
	while(x){
		if(x&1){
			sum = add_algorithm(sum,y);
		}
		x>>=1;
		y<<=1;
	}
	return sum;
}
int main(){
	cout<<multiple_algorithm(300,1234);
}