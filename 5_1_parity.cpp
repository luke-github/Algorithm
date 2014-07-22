#include <iostream>
using namespace std;

bool parity_algorithm(int x){
	int result = 0;
	while(x){
		result ^= 1;
		x &= (x-1);
	}
	return result;
}

int main(){
	cout<<parity_algorithm(4);
}