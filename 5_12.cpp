#include <iostream>
#include <time.h>
using namespace std;

int random_generator(int a, int b){
	int t = abs(a-b)+1;
	int res = 0;
	do{
		res = 0;
		for(int i=0;(1<<i)<t;i++){
			res = (res<<1) | zero_one_random();
		}
	}while(res>=t);
	return a+res;
}

int main(){
}