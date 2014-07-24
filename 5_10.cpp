#include <iostream>
using namespace std;

int reverse_algorithm(int n){
	int res = 0;
	while(n){
		res = res*10 + n%10;
		n /= 10;
	}
	return res;
}

int main(){
	cout<<reverse_algorithm(12345);
}