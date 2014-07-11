#include <iostream>
#include <vector>
using namespace std;

int min_result(int a, int b, int c){
	return min(a, min(b,c));
}

int distance_algorithm(string a,string b){
	int dp[a.size()+1][b.size()+1];
	for(int i=0;i<=a.size();i++){
		dp[i][0]=i;
	}
	for(int j=0;j<=b.size();j++){
		dp[0][j]=j;
	}
	for(int i=1;i<=a.size();i++){
		for(int j=1;j<=b.size();j++){
			if(a[i-1]==b[j-1]){
				dp[i][j]=dp[i-1][j-1];
			}else{
				dp[i][j]=1+min_result(dp[i-1][j-1],dp[i][j-1],dp[i-1][j]);
			}
		}
	}
	return dp[a.size()][b.size()];
}

int main(){
	string a = "abc";
	string b = "b";
	cout<<distance_algorithm(a,b);
}