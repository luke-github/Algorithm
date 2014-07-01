#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void dispatch_anagram(const vector<string>& dict){
	unordered_map<string,vector<string>> hash;
	for(const string& s : dict){
		string sorted_str(s);
		sort(sorted_str.begin(),sorted_str.end());
		hash[sorted_str].emplace_back(s);
	}
	for(const pair<string,vector<string>>& p : hash){
		if(p.second.size()>1){
			for(const string& x : p.second){
				cout<<x<<":";
			}
			cout<<endl;
		}
	}
}

int main(){
	vector<string> input = {"abc","acb","bac","qwe","ewq","wqe","wsx","wxs"};
	dispatch_anagram(input);
}