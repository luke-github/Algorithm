#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>
using namespace std;

int minimal_difference(vector<int>& vec){
	int total = accumulate(vec.begin(),vec.end(),0);
	unordered_set<int> dp;
	dp.emplace(0);
	for(int x : vec){
		for(int i=total>>1;i>=x;i--){
			if(dp.find(i-x)!=dp.end()){
				dp.emplace(i);
			}
		}
	}
	for(int i=total>>1;i>=0;i--){
		if(dp.find(i)!=dp.end()){
			return total-i-i;
		}
	}
	return total;
}

int main(){
	vector<int> input = {1,2,3,5};
	cout<<minimal_difference(input);
}