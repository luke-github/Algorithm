#include <iostream>
#include <vector>
using namespace std;

pair<int,int> pretty_printing_algorithm(vector<string>& vec, int line_length){
	vector<int> dp(vec.size(),(1<<31)-1);
	int result_with_ll;
	int result_without_ll;
	for(int i=0;i<vec.size();i++){
		int b_len = line_length - vec[i].size();
		dp[i] = min((i==0?0:dp[i-1])+(1<<b_len),dp[i]);
		for(int j=i-1;j>=0;j--){
			b_len -= (vec[j].size()+1);
			if(b_len<0){
				break;
			}
			dp[i] = min(j==0?0:dp[j-1]+(1<<b_len),dp[i]);
		}
	}
	result_with_ll = dp[vec.size()-1];
	result_without_ll = (vec.size()>=2?dp[vec.size()-2]:0);
	int b_len = line_length - vec.back().size();
	for(int i=vec.size()-2;i>=0;i--){
		b_len -= (vec[i].size()+1);
		if(b_len<0){
			return {result_with_ll,result_without_ll};
		}
		result_without_ll = min(result_without_ll,dp[i-1]);
	}
	return {result_with_ll,result_without_ll};
}

int main(){
	vector<string> input = {"aa","aa","a","aa","aa"};
	auto res = pretty_printing_algorithm(input,3);
	cout<<res.first<<" "<<res.second;
}