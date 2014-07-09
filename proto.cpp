#include <iostream>
#include <vector>
using namespace std;

void combination_handler(int n, int k, int start, vector<int>* ans, vector<vector<int>>* res){
	if(k==ans->size()){
		res->emplace_back(*ans);
		return;
	}
	if(k - ans->size() <= n - (start+1)){
		combination_handler(n,k,start+1,ans,res);
	}
	ans->emplace_back(start+1);
	combination_handler(n,k,start+1,ans,res);
	ans->pop_back();
}

vector<vector<int>> combination(int n, int k){
	vector<int> ans;
	vector<vector<int>> res;
	combination_handler(n,k,0,&ans,&res);
	return res;
}

int main(){
	auto res = combination(10,2);
	for(auto x : res){
		for(auto y: x){
			cout<<y<<" ";
		}
		cout<<endl;
	}
}