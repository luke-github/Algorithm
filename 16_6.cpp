#include <iostream>
#include <vector>
using namespace std;

void find_combination_handler(int n, int k, int start, vector<int>* ans, vector<vector<int>>* res){
	if(ans->size()==k){
		res->emplace_back(*ans);
		return;
	}
	if(k - ans->size() <= n - (start+1)){
		find_combination_handler(n,k,start+1,ans,res);
	}
	ans->emplace_back(start+1);
	find_combination_handler(n,k,start+1,ans,res);
	ans->pop_back();
}

vector<vector<int>> find_combination(int n,int k){
	vector<vector<int>> res;
	vector<int> ans;
	find_combination_handler(n,k,0,&ans,&res);
	return res;
}

int main(){
	auto res = find_combination(5,2);
	for(vector<int> m : res){
		for(int x : m){
			cout<<x<<",";
		}
		cout<<endl;
	}
}