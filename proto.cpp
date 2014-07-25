#include <complex>
#include <iostream>
using namespace std;

bool perfect_square_checker(int x){
	double square_x = sqrt(x);
	int floor_x = floor(square_x);
	return x==floor_x*floor_x;	
}

int main(){
	cout<<perfect_square_checker(25);
}