#include <iostream>
using namespace std;

unsigned add_algorithm(unsigned x, unsigned y){
	unsigned sum =0, carryin = 0, temp_a= x, temp_b =y, k=1;
	while(temp_a||temp_b){
		unsigned xk= x&k, yk=y&k;
		unsigned carryout = (xk&yk) | (carryin&xk) | (carryin&yk);
		sum |= (xk^yk^carryin);
		carryin = carryout<<1;
		k<<=1;
		temp_a>>=1;
		temp_b>>=1;
	}
	return sum | carryin;
}

unsigned multiply_algorithm(unsigned x, unsigned y){
	unsigned sum = 0;
	while(x){
		if(x&1){
			sum = add_algorithm(sum,y);
		}
		y<<=1;
		x>>=1;
	}
	return sum;
}

int main(){
	cout<<multiply_algorithm(2,3);
}
