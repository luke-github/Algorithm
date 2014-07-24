#include <iostream>
#include <complex>

using namespace std;

bool check_parlidrome(int x){
	if(x<0){
		return false;
	}
	int num_digits = floor(log10(x))+1;
	int temp_x  = x;
	int shifts = pow(10,num_digits - 1);
	for(int i=0;i<(num_digits>>1);i++){
		if(x/shifts != temp_x%10){
			return false;
		}
		x %= shifts;
		shifts /=10;
		temp_x /=10;
	}
	return true;
}

int main(){
	cout<<check_parlidrome(323);
}