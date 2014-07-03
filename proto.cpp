#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool check_collatz_conjecture(int n){
	unordered_set<long> table;
	for(int i=2;i<=n;i++){
		unordered_set<long> sequence;
		int test_i = i;
		while(test_i>i){
			if(!sequence.emplace(test_i).second){
				return false;
			}
			if(test_i&1){
				if(!table.emplace(test_i).second){
					break;
				}
				test_i=3*test_i+1;
			}else{
				test_i=test_i>>1;
			}
		}
	}
	return true;
}

int main(){
	cout<<check_collatz_conjecture(100);
}