#include <iostream>
using namespace std;
int main(){
	bitset<8> bit_set;
	bit_set.set(1);
	bit_set.set(2);
	bit_set.set(3);
	cout<<bit_set.test(4);

}