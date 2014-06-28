#include <iostream>
#include <queue>
using namespace std;

struct Compare{
	bool operator()(const pair<int,int>& l,const pair<int,int>& r){
		return l.first > r.first;
	}
};

vector<int> merge_sort(const vector<vector<int>>& vec){
	priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> mini_heap;
	vector<int> result;
	vector<int> index(vec.size(),0);
	for(int i=0;i<vec.size();i++){
		if(vec[i].size()>0){
			mini_heap.emplace(vec[i][0],i);
			index[i]=1;
		}
	} 
	while(!mini_heap.empty()){
		pair<int,int> mini = mini_heap.top();
		result.emplace_back(mini.first);
		if(index[mini.second]<vec[mini.second].size()){
			mini_heap.emplace(vec[mini.second][index[mini.second]++],mini.second);
			
		}
		mini_heap.pop();
	}
	return result;
}

vector<int> k_increasing_decreasing(vector<int>& vec){
	vector<vector<int>> result;
	int start_index=0;
	bool is_increasing = true;
	for(int i=1;i<vec.size();i++){
		if((vec[i-1]<vec[i]&&!is_increasing)||(vec[i-1]>=vec[i]&&is_increasing)){
			if(is_increasing){
				result.emplace_back(vec.cbegin()+start_index,vec.cbegin()+i);
			}else{
				result.emplace_back(vec.crbegin()+vec.size()-i,vec.crbegin()+vec.size()-start_index);
			}
			start_index = i;
			is_increasing = !is_increasing;
		}
	}
	if(is_increasing){
		result.emplace_back(vec.cbegin()+start_index,vec.cend());
	}else{
		result.emplace_back(vec.crbegin(),vec.crbegin()+vec.size()-start_index);
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






















