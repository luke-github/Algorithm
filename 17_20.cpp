#include <iostream>
#include <vector>
using namespace std;

int pretty_printing_algorithm(vector<string>& vec, int line_length){
	vector<int> dp(vec.size(),(1<<31)-1);
	for(int i=0;i<vec.size();i++){
		int b_len = line_length - vec[i].size();
		dp[i] = min((i<1)?0:dp[i-1]+(1<<b_len),dp[i]);
		for(int j=i-1;j>=0;j--){
			b_len -= (vec[j].size()+1);
			if(b_len<0){
				break;
			}
			dp[i] = min(dp[i],(j<1?0:dp[j-1]+(1<<b_len)));
		}
	}
	int result_consider_last_line = dp[vec.size()-1];

	int min_result = (vec.size()>=2?dp[vec.size()-2]:0);
	int b_len = line_length - vec.back().size();
	for(int i = vec.size()-2;i>=0;i--){
		b_len -= (vec[i].size()+1);
		if(b_len<0){
			return min_result;
		}
		min_result = min(min_result,dp[i-1]);
	}
	return min_result;
}

int main(){
	vector<string> input = {"aa","aa","a","aa","aa"};
	cout<<pretty_printing_algorithm(input,3);
}