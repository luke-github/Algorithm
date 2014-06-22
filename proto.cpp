#include <iostream>
using namespace std;


void test(int *m){
	cout<<*m;
}


int main(){
	int a=3;
	int* pointer = &a;
	test(pointer);
}