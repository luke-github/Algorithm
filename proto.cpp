// this solution is very smart
#include <iostream>
#include <queue>
#include <list>
using namespace std;

list<int> minimal_step(int n){
	if(n==1){
		return {1};
	}
	queue<list<int>> exp_lists;
	exp_lists.emplace(1,1);
	while(!exp_lists.empty()){
		list<int> cur_exp = exp_lists.front();
		exp_lists.pop();
		for(int x: cur_exp){
			int sum = x + cur_exp.back();
			if(sum>n){
				break;
			}
			list<int> new_exp(cur_exp);
			new_exp.emplace_back(sum);
			if(sum==n){
				return new_exp;
			}
			exp_lists.emplace(new_exp);
		}
	}
}

int main(){
	auto res = minimal_step(15);
	for(int x : res){
		cout<<x<<" ";
	}
}