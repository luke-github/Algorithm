#include <iostream>
#include <complex>
using namespace std;

bool perfect_square_algorithm(int x){
	double square_x = sqrt(x);
	int floor_sqr_x = floor(square_x);
	return x == floor_sqr_x*floor_sqr_x;
}

int main(){
	cout<<perfect_square_algorithm(49);
}