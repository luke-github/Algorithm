#include <iostream>
#include <queue>
using namespace std;

struct cmp{
	bool operator()(const pair<int,int>& l, const pair<int,int>& r){
		return l.first>r.first;
	}
};

vector<int> merge_sort(vector<vector<int>>& vec){
	priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> mini_heap;
	vector<int> result;
	vector<int> index(vec.size(),0);
	for(int i=0;i<vec.size();i++){
		if(vec[i].size()>0){
			mini_heap.emplace(vec[i][0],i);
			index[i]=1;
		}
	}
	while(!mini_heap.empty()){
		pair<int,int> mini_result = mini_heap.top();
		result.emplace_back(mini_result.first);
		if(index[mini_result.second]<vec[mini_result.second].size()){
			mini_heap.emplace(vec[mini_result.second][index[mini_result.second]++],mini_result.second);
		}
		mini_heap.pop();
	}
	return result;
}

vector<int> k_increasing_decreasing(const vector<int>& input){
	vector<vector<int>> result;
	bool is_increasing = true;
	int start_index = 0;
	for(int i=1;i<input.size();i++){
		if((input[i-1]<input[i]&&!is_increasing)||(input[i-1]>=input[i]&&is_increasing)){
			if(is_increasing){
				result.emplace_back(input.cbegin()+start_index,input.cbegin()+i);
			}else{
				result.emplace_back(input.crbegin()+input.size()-i,input.crbegin()+input.size()-start_index);
			}
			start_index = i;
			is_increasing=!is_increasing;
		}
	}
	if(is_increasing){
		result.emplace_back(input.cbegin()+start_index,input.cend());
	}else{
		result.emplace_back(input.crbegin(),input.crbegin()+input.size()-start_index);
	}
	return merge_sort(result);
}

int main(){
	vector<int> input = {1,3,5,4,2,6,8,7,5};
	vector<int> res = k_increasing_decreasing(input);
	for(int x : res){
		cout<<x<<" ";
	}
}


