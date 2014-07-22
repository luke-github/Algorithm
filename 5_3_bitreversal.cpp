// #include<iostream>
// #include<vector>
// using namespace std;

// vector<long> precompute;

// long reverseLong(const long &x){
// 	return ((x>>48)&0xFFFF) |
// 	(((x>>32)&0xFFFF)<<16) |
// 	(((x>>16)&0xFFFF)<<32) |
// 	((x&0xFFFF)<<48);
// }

// int main(){
// 	long input=281474976710656;
// 	cout<<reverseLong(input);
// }

// #include <iostream>
// using namespace std;

// int main(){
// 	int res = 3^1;
// 	cout<<res;
// }

#include <iostream>
using namespace std;

long reverse(long x){
	return precompute[x>>48&0xffff] |
			precompute[((x>>32)&0xffff)<<16] |
			precompute[((x>>16)&0xFFFF)<<32] |
			precompute[(x&0xFFFF)<<48];
}