#include <iostream>
using namespace std;

int main(){
	int a = 10;
	int b(move(a));
	cout<<b<<endl;
	cout<<a;
}