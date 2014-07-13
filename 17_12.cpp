#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<string> word_breaking_algorithm(unordered_set<string>& dict, string& s){
	vector<int> dp(s.size(),0);
	vector<string> res;
	for(int i=0;i<s.size();i++){
		if(dict.find(s.substr(0,i+1))!=dict.end()){
			dp[i]=i+1;
		}
		for(int j=0;j<i&&dp[i]==0;j++){
			if(dp[j]!=0&&dict.find(s.substr(j+1,i-j))!=dict.end()){
				dp[i]=i-j;
			}
		}
	}
	int index = s.size()-1;
	if(dp.back()){
		while(index>=0){
			res.emplace_back(s.substr(index-dp[index]+1,dp[index]));
			index = index - dp[index];
		}
	}
	reverse(res.begin(),res.end());
	return res;
}

int main(){
	unordered_set<string> dic = {"ab","cd","ac","bcc","m"};
	string s = "ababacm";
	auto result = word_breaking_algorithm(dic,s);
	for(auto x : result){
		cout<<x<<" ";
	}
}