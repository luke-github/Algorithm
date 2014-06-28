#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

void almost_sorted(istringstream* sin, int k){
	priority_queue<int,vector<int>,greater<int>> min_queue;
	int x;
	for(int i=0;i<k&&*sin>>x;i++){
		min_queue.emplace(x);
	}
	while(*sin>>x){
		min_queue.emplace(x);
		cout<<min_queue.top()<<" ";
		min_queue.pop();
	}
	while(!min_queue.empty()){
		cout<<min_queue.top()<<" ";
		min_queue.pop();
	}
}
int main(){
	string input = " 5 4 3 1 2 8 10 9 13 15 11";
	istringstream ss(input);
	almost_sorted(&ss,3);
}