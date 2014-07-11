#include <iostream>
#include <vector>
using namespace std;

int ways_algorithm_with_obstacle(int m, int n, vector<vector<int>>& vec){
	vector<vector<int>> dp(m,vector<int>(n,0));
	if(vec[0][0]){
		return 0;
	}
	dp[0][0]=1;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(vec[i][j]==0){
				dp[i][j] += (i<1?0:dp[i-1][j])+(j<1?0:dp[i][j-1]);
				cout<<dp[i][j]<<" ";
			}
		}
		cout<<endl;
	}
	return dp[m-1][n-1];
}

int main(){
	vector<vector<int>> input(10,vector<int>(10,0));
	input[2][1]=1;
	cout<<ways_algorithm_with_obstacle(10,10,input)<<endl;
}