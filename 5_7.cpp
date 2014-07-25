#include <iostream>
using namespace std;

double pow_algorithm(double x, int y){
	double res = 1.0;
	long long power = y;
	if(y<0){
		x = 1.0/x;
		power = -power;
	}
	while(power){
		if(power&1){
			res *= x;
		}
		x *= x, power>>=1;
	}
	return res;
}
int main(){
	cout<<pow_algorithm(2,-5);
} 