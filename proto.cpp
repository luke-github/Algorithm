#include <iostream>
#include <vector>
using namespace std;

pair<int,int> find_min_max(vector<int>& vec){
	if(vec.size()<=1){
		return {vec.front(),vec.front()};
	}
	pair<int,int> result = minmax(vec[0],vec[1]);
	for(int i=2;i<vec.size()-1;i++){	
		pair<int,int> local = minmax(vec[i],vec[i+1]);
		result = {min(result.first,local.first),
					max(result.second,local.second)};
	}
	if(vec.size()&1){
		result = {min(result.first,vec.back()),
			max(result.second, vec.back())};
	}
	return result;
}


int main(){
	vector<int> input = {1,2,3,4,5,6,7,8,9,0};
	pair<int,int> res = find_min_max(input);
	cout<<res.first<<" "<<res.second;
}