#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int max_product(const vector<int>& vec){
	vector<int> L,R(vec.size());
	partial_sum(vec.begin(),vec.end(),back_inserter(L),multiplies<int>());
	partial_sum(vec.rbegin(),vec.rend(),R.rbegin(),multiplies<int>());
	int max_val = 1<<31;
	for(int i=0;i<vec.size();i++){
		int forward = i>0?L[i-1]:1;
		int backward = i+1<vec.size()?R[i+1]:1;
		max_val = max(max_val,forward*backward);
	}
	return max_val;
}

int main(){
	vector<int> input = {1,2,3,-4};
	cout<<max_product(input);
}