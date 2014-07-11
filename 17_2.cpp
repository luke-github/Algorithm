#include <iostream>
#include <vector>
using namespace std;

int min_result(int a, int b, int c){
	return min(a, min(b,c));
}

int distance_algorithm(string& s1, string& s2){
	int length1 = s1.size();
	int length2 = s2.size();
	int dp[length1+1][length2+1];
	for(int i=0;i<=s1.size();i++){
		dp[i][0]=i;
	}
	for(int j=0;j<=s2.size();j++){
		dp[0][j]=j;
	}
	for(int i=1;i<=s1.size();i++){
		for(int j=1;j<=s2.size();j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j]=dp[i-1][j-1];
			}else{
				dp[i][j]=1+min_result(dp[i-1][j-1],dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[s1.size()][s2.size()];
}

int main(){
	string s1 = "abc";
	string s2 = "ae";
	cout<<distance_algorithm(s1,s2);
}