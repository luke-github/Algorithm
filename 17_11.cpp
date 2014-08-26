#include <iostream>
#include <vector>
using namespace std;

int uncircular_max_handler(vector<int>& vec){
	int max_till = 0, sum =0, max_result=0;
	for(int i=0;i<vec.size();i++){
		max_till = max(max_till+vec[i],vec[i]);
		max_result = max(max_result,max_till);
	}
	return max_result;
}

int circular_max_handler(vector<int>& vec){
	vector<int> max_begin;
	int sum = vec[0];
	max_begin.emplace_back(sum);
	for(int i=1;i<vec.size();i++){
		sum += vec[i];
		max_begin.emplace_back(max(sum,max_begin.back()));
	}
	vector<int> max_end(vec.size());
	max_end.back() = 0;
	sum = 0;
	for(int i=vec.size()-2;i>=0;i--){
		sum += vec[i+1];
		max_end[i] = max(max_end[i+1],sum);
	}
	int res = 0;
	for(int i=0;i<vec.size();i++){
		res = max(res, max_begin[i]+max_end[i]);
	}
	return res;
}

int max_subarray(vector<int>& vec){
	return max(circular_max_handler(vec),uncircular_max_handler(vec));
}