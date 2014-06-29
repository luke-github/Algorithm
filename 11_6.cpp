#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct cmp{
	bool operator ()(const pair<int,int>& p1,const pair<int,int>& p2){
		return p1.second< p2.second;
	}
};

vector<int> k_largest_element(vector<int>& vec, int k){
	vector<int> result;
	priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> max_heap;
	max_heap.emplace(0,vec[0]);
	for(int i=0;i<k;i++){
		int res = max_heap.top().second;
		int index = max_heap.top().first;
		result.emplace_back(res);
		max_heap.pop();
		if((index<<1)+1<vec.size()){
			max_heap.emplace(((index<<1)+1),vec[(index<<1)+1]);
		}
		if((index<<1)+2<vec.size()){
			max_heap.emplace(((index<<1)+2),vec[(index<<1)+2]);
		}
	}
	return result;
}

int main(){
	vector<int> input = {100,90,50,89,87,49,48,86,85,84,83,47,46,45,44};
	vector<int> result = k_largest_element(input,5);
	for(int x : result)
		cout<<x<<" ";
}