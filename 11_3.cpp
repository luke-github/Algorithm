#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

void sort_sequence(istringstream* sin, int k){
	priority_queue<int,vector<int>,greater<int>> min_heap;
	int x;
	for(int i=0;i<k&&*sin>>x;i++){
		min_heap.emplace(x);
	}
	while(*sin>>x){
		min_heap.emplace(x);
		cout<<min_heap.top()<<" ";
		min_heap.pop();
	}
	while(!min_heap.empty()){
		cout<<min_heap.top()<<" ";
		min_heap.pop();
	}
}

int main(){
	string input = "5 4 3 2 1";
	istringstream in(input);
	sort_sequence(&in,5);
}