#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int subsum_algorithm(vector<int>& vec, int target){
	int total = accumulate(vec.begin(),vec.end(),0);
	vector<vector<int>> dp(vec.size()+1,vector<int>(total+1,0));
	dp[0][0]=1;
	for(int i=0;i<vec.size();i++){
		for(int j=0;j<=total;j++){
			dp[i+1][j]=dp[i][j]+(j<vec[i]?0:dp[i][j-vec[i]]);
		}
	}
	for(auto x: dp){
		for(auto y:x){
			cout<<y<<" ";
		}
		cout<<endl;
	}
	return dp[vec.size()][target];
}

int main(){
	vector<int> input = {1,3,2,4};
	cout<<subsum_algorithm(input,4);
}