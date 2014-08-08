#include <iostream>
#include <vector>
using namespace std;

pair<int,int> longest_increasing_subarray(const vector<int>& vec){
	int max_len = 1;
	pair<int,int> ans(0,0);
	int i = 0;
	while(i<vec.size()){
		bool is_skip = false;
		for(int j = i+max_len-1;j>=i;j--){
			if(j+1>=vec.size()||vec[j]>vec[j+1]){
				i = j+1;
				is_skip = true;
				break;
			}
		}
		if(is_skip==false){
			i += max_len-1;
			while(i+1<vec.size()&&vec[i]<vec[i+1]){
				i++;max_len++;
			}
			ans = {i - max_len+1,i};
		}

	}
	return ans;
}

int main(){
	vector<int> input = {1,2,3,4,3,4,5,6,7,8};
	auto res = longest_increasing_subarray(input);
	cout<<res.first<<" "<<res.second<<endl;
}