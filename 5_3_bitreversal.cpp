#include<iostream>
#include<vector>
using namespace std;

vector<long> precompute;

long reverseLong(const long &x){
	return ((x>>48)&0xFFFF) |
	(((x>>32)&0xFFFF)<<16) |
	(((x>>16)&0xFFFF)<<32) |
	((x&0xFFFF)<<48);
}

int main(){
	long input=281474976710656;
	cout<<reverseLong(input);
}

