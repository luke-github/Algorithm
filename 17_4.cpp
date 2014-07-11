#include <iostream>
#include <vector>
using namespace std;

int num_ways(int n, int m){
	if(n<m){
		swap(n,m);
	}
	vector<vector<int>> A(2,vector<int>(m,1));
	for(int i=1;i<n;i++){
		for(int j=0;j<m;j++){
			A[i&1][j]=(i<1?0:A[(i-1)&1][j])+(j<1?0:A[i&1][(j-1)]);
		}
	}
	return A[(n-1)&1][m-1];
}

int way_algorithm(int a, int b){
	int dp[a][b];
	for(int i=0;i<a;i++){
		dp[i][0]=1;
	}
	for(int j=0;j<b;j++){
		dp[0][j]=1;
	}
	for(int i=1;i<a;i++){
		for(int j=1;j<b;j++){
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return dp[a-1][b-1];
}

int ways_with_bostacle_algorithm(int m, int n, vector<vector<int>>& vec){
	vector<vector<int>> dp(m,vector<int>(n,0));
	if(vec[0][0]){
		return 0;
	}
	dp[0][0]=1;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(vec[i][j]==0){
				dp[i][j]+=(i<1?0:dp[i-1][j])+(j<0?0:dp[i][j-1]);
			}
		}
	}
	return dp[m-1][n-1];
}

int main(){
	// cout<<way_algorithm(5,3);
	vector<vector<int>> input(3,vector<int>(3,0));
	input[1][1]=1;
	cout<<ways_with_bostacle_algorithm(3,3,input);
}