#include <iostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>
using namespace std;


int range_algo(int a, unordered_set<int>& S, unordered_map<int,int>* L){
	if(S.find(a)==S.end()){
		return 0;
	}
	if(L->find(a)==L->end()){
		(*L)[a] = range_algo(a-1,S,L)+1;
	}
	return (*L)[a];
}

pair<int,int> longest_range(const vector<int>& vec){
	unordered_set<int> S;
	for(int x: vec){
		S.emplace(x);
	}

	int max_len=0;
	pair<int,int> max_range(-1,0);
	unordered_map<int,int> L;
	for(int x: vec){
		int len = range_algo(x,S,&L);
		if(len > max_len){
			max_len = len;
			max_range = {x - len +1, x};
		}
	}
	return max_range;
}

int main(){
	vector<int> input = {1,2,3,4,5,7,8,9,10,11,12,13};
	auto res = longest_range(input);
	cout<<res.first<<" "<<res.second<<endl;
}