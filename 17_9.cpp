#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int ways_of_tie_algorithm(vector<int>&vec, int subsum){
	int total = accumulate(vec.begin(),vec.end(),0);
	vector<vector<int>> dp(vec.size()+1,vector<int>(total+1,0));
	dp[0][0]=1;
	for(int i=0;i<vec.size();i++){
		for(int j=0;j<=total;j++){
			dp[i+1][j]=dp[i][j]+(vec[i]>j?0:dp[i][j-vec[i]]);
		}
	}
	for(auto x: dp){
		for(auto y: x){
			cout<<y<<" ";
		}
		cout<<endl;
	}
	return dp[vec.size()][subsum];
}

int main(){
	vector<int> input = {1,3,2,4};
	cout<<ways_of_tie_algorithm(input,3);
}