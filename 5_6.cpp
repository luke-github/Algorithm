#include <iostream>
using namespace std;

int divide_func(int x, int y){
	int res = 0;
	while(x>=y){
		int power = 1;
		while((y<<power)>=(y<<(power-1))&&((y<<power)<=x)){
			power++;
		}
		res += 1<<(power-1);
		x -= y<<(power-1);
	}
	return res;
}

int main(){
	cout<<divide_func(8,3);
}