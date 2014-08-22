#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> pair_algorithm(vector<int>& vec){
	vector<pair<int,int>> res;
	sort(vec.begin(),vec.end());
	for(int i=0,j=vec.size()-1;i<j;i++,j--){
		res.emplace_back(vec[i],vec[j]);
	}
	return res;
}

int main(){
	vector<int> input = {1,3,5,8,10,19};
	auto res = pair_algorithm(input);
	for(auto x : res){
		cout<<x.first<<" "<<x.second<<endl;
	}
}