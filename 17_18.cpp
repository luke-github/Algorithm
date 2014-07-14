#include <iostream>
#include <vector>
using namespace std;

int number_steps_algorithm(int n, int k){
	vector<int> dp(n+1,0);
	dp[0]=dp[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i&&j<=k;j++){
			dp[i]+=dp[i-j];
		}
	}
	return dp[n];
}

int main(){
	cout<<number_steps_algorithm(4,2);
}