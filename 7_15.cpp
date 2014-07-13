#include <iostream>
#include <vector>
using namespace std;

int max_profit_algorithm_handler(vector<int>& vec, int a, int b, vector<vector<int>>* dp){
	if(a>b){
		return 0;
	}
	if((*dp)[a][b]==-1){
		(*dp)[a][b] = max(vec[a]+min(max_profit_algorithm_handler(vec,a+1,b-1,dp),max_profit_algorithm_handler(vec,a+2,b,dp)),
			vec[b]+min(max_profit_algorithm_handler(vec,a+1,b-1,dp),max_profit_algorithm_handler(vec,a,b-2,dp)));
	}
	return (*dp)[a][b];
}

int max_profit_algorithm(vector<int>& vec){
	vector<vector<int>> dp(vec.size(),vector<int>(vec.size(),-1));

	int res = max_profit_algorithm_handler(vec,0,vec.size()-1,&dp);
	for(auto x: dp){
		for(auto y:x){
			cout<<y<<"   ";
		}
		cout<<endl;
	}
	return res;
}

int main(){
	vector<int> input = {1,2,3,4,5,6};
	cout<<max_profit_algorithm(input);
}
