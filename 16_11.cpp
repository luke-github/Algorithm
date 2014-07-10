#include <iostream>
#include <vector>
using namespace std;

vector<int> gray_code_algorithm(int n){
	if(n==0){
		return {0};
	}
	if(n==1){
		return {0,1};
	}
	vector<int> pre_res = gray_code_algorithm(n-1);
	vector<int> res;
	int leading_one = 1<<(n-1);
	for(int i=pre_res.size()-1;i>=0;i--){
		res.emplace_back(leading_one+pre_res[i]);
	}
	pre_res.insert(pre_res.end(),res.begin(),res.end());
	return pre_res;
}

int main(){
	auto res = gray_code_algorithm(5);
	for(auto x : res){
		cout<<x<<" ";
	}
}