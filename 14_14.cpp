#include <iostream>
#include <vector>
#include  <numeric>
using namespace std;

double complelation_search(int budget, vector<double> vec){
	sort(vec.begin(),vec.end());
	vector<double> pre_sum;
	partial_sum(vec.begin(),vec.end(),back_inserter(pre_sum));
	vector<double> cost;
	for(int i=0;i<pre_sum.size();i++){
		cost.emplace_back(pre_sum[i]+vec[i]*(vec.size()-i-1));
	}
	auto lower_pt = lower_bound(cost.begin(),cost.end(),budget);
	if(lower_pt==cost.cend()){
		return -1.0;
	}else if(lower_pt==cost.begin()){
		return budget/vec.size();
	}
	int index = distance(cost.begin(),lower_pt)-1;
	return vec[index]+(budget-cost[index])/(vec.size()-index-1);
}	

int main(){
	vector<double> input = {1,2,3,4,5,6,7,8,9};
	cout<<complelation_search(10,input);
}