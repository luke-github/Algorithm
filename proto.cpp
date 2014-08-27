#include <iostream>
#include <vector>
using namespace std;

int longest_nondecreasing_subarray(vector<int>& vec){
	vector<int> res;
	for(int x : vec){
		auto it = upper_bound(res.begin(),res.end(),x);
		if(it==res.end()){
			res.emplace_back(x);
		}else{
			*it = x;
		}
	}
	return res.size();
}
