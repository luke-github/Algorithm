#include <iostream>
#include <unordered_set>
using namespace std;

bool collatz_conjecture(int n){
	unordered_set<long> table;
	for(int i=2;i<=n;i++){
		unordered_set<long> sequence;
		long test_i = i;
		while(test_i>=i){
			if(!sequence.emplace(test_i).second){
				return false;
			}
			if(test_i&1){
				if(!table.emplace(test_i).second){
					break;
				}
				long next_test_i = 3*test_i+1;
				test_i=next_test_i;
			}else{
				test_i=test_i>>1;
			}

		}
	}
	return true;
}

int main(){
	cout<<collatz_conjecture(11);
}