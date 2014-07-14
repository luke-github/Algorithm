#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int ways_parlidrom_algorithm(string& s){
	vector<vector<bool>> checker(s.size(),vector<bool>(s.size(),false));
	vector<int> dp(s.size()+1);
	iota(dp.rbegin(),dp.rend(),0);
	for(int i=s.size()-1;i>=0;i--){
		for(int j=i;j<s.size();j++){
			if(s[i]==s[j]&&(j-i<2||checker[i+1][j-1])){
				checker[i][j]=true;
				dp[i] = min(dp[i],1+dp[j+1]);
			}
		}
	}
	return dp[0];
}


int main(){
	string input = "acad";
	cout<<ways_parlidrom_algorithm(input);
}