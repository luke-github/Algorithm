#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

double complete_search(double budget,vector<double>& vec){
	sort(vec.begin(),vec.end());
	vector<double> pre_sum;
	partial_sum(vec.begin(),vec.end(),back_inserter(pre_sum));
	vector<double> costs;
	for(int i=0;i<vec.size();i++){
		costs.emplace_back(pre_sum[i]+vec[i]*(vec.size()-i-1));
	}
	auto it = lower_bound(costs.begin(),costs.end(),budget);
	if(it==costs.cend()){
		return -0.1;
	}else if(it==costs.begin()){
		return budget/vec.size();
	}
	int index = distance(costs.begin(),it)-1;
	return vec[index]+(budget - costs[index])/(vec.size()-index-1);
}

int main(){
	vector<double> input = {1,2,3,4,5,6,7,8,9};
	cout<<complete_search(30,input);
}