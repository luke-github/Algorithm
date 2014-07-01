#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void dispatch_anagram(const vector<string>& dic){
	unordered_map<string,vector<string>> hash;
	for(string s:dic){
		string sorted_str(s);
		sort(sorted_str.begin(),sorted_str.end());
		hash[sorted_str].emplace_back(s);
	}
	for(const pair<string,vector<string>> p : hash){
		if(p.second.size()>1){
			for(const string s : p.second){
				cout<<s<<":";
			}
			cout<<endl;
		}
	}
}

int main(){
	vector<string> input = {"abc","acb","bac","qwe","ewq","wqe","wsx","wxs"};
	dispatch_anagram(input);
}