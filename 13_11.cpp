#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int longest_distinct_subarry(const vector<int>& vec){
	unordered_map<int,int> last_occurance;
	size_t start_index=0, ans=0;
	for(size_t i=0;i<vec.size();i++){
		auto res(last_occurance.emplace(vec[i],i));
		if(!res.second){
			if(res.first->second >= start_index){
				ans = max(ans,i - start_index);
				start_index = res.first->second + 1;
			}
			res.first->second = i;
		}
	}
	ans = max(ans, vec.size() - start_index);
	return ans;
}

int main(){
	vector<int> input = {1,2,3,1,2,3,4,5};
	cout<<longest_distinct_subarry(input);
}