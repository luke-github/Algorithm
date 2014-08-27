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
	for(int x : res){
		cout<<x<<" ";
	}
	cout<<endl;
	return res.size();
}

int main(){
	vector<int> input = {0,8,4,12,2,10,6,14,1,9};
	cout<<longest_nondecreasing_subarray(input);
}