#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
using namespace std;

vector<int> prime_func(int n){
	int size = floor(0.5*(n-3))+1;
	vector<int> res;
	deque<bool> is_prime(size,true);
	res.emplace_back(2);
	
	for(int i=0;i<size;i++){
		if(is_prime[i]){
			int p =  (i<<1)+3;
			res.emplace_back(p);
			for(int j = 2*i*i+6*i+3;j<size;j+=p){
				is_prime[j]=false;
			}
		}
	}
	return res;
}

int main(){
	auto res = prime_func(1000);
	for(auto x : res){
		cout<<x<<" ";
	}
}