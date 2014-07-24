#include <complex>
#include <iostream>
using namespace std;

bool checker_parlidrome(int x){
	if(x<0){
		return false;
	}
	int num_digits = floor(log10(x))+1;
	int temp_x = x;
	int shift = pow(10,num_digits-1);
	for(int i=0;i<(num_digits>>1);i++){
		if(x/shift != temp_x%10){
			return false;
		}
		x %= shift;
		shift /=10;
		temp_x /=10;
	}
	return true;
}

int main(){
	cout<<checker_parlidrome(1333333331);
}