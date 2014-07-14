#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int ways_parlidrome_algorithm(const string& s){
	vector<vector<bool>> checker(s.size(),vector<bool>(s.size(),false));
	vector<int> dp(s.size()+1);
	iota(dp.begin(),dp.end(),0);
	for(int i=0;i<s.size();i++){
		for(int j=i;j>=0;j--){
			if(s[i]==s[j]&&(i-j<2||checker[j+1][i-1])){
				checker[j][i]=true;
				dp[i] = min(dp[i],1+dp[j-1]);
			}
		}
	}
	return dp[s.size()-1];
}


int main(){
	string input = "ad";
	cout<<ways_parlidrome_algorithm(input);
}