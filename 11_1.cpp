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

int main(){
	vector<vector<int>> vec={{1,10,100},{2,20,200},{3,30,300}};
	vector<int> res = merge_sort(vec);
	for(int x : res){
		cout<<x<<" ";
	}
}