#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longest_distinct_subarray(const vector<int>& vec){
	unordered_map<int,int> last_occurrence;
	size_t first_index=0, ans=0;
	for(int i=0;i<vec.size();i++){
		auto res(last_occurrence.emplace(vec[i],i));
		if(!res.second){
			if(res.first->second >= first_index){
				ans = max(ans,i - first_index);
				first_index = res.first->second+1;
			}
			res.first->second = i;
		}
	}
	ans = max(ans,vec.size()-first_index);
	return ans;
}


int main(){
	vector<int> input = {1,2,3,1,2,3,4,5};
	cout<<longest_distinct_subarray(input);
}