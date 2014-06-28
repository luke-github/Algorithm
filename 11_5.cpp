#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;

void online_median(istringstream* sin){
	priority_queue<int,vector<int>,greater<int>> high;
	priority_queue<int,vector<int>,less<int>> low;
	int x;
	while(*sin>>x){
		if(!low.empty()&&x>low.top()){
			high.emplace(x);
		}else{
			low.emplace(x);
		}
		if(high.size()>low.size()+1){
			low.emplace(high.top());
			high.pop();
		}else if(low.size()>high.size()+1){
			high.emplace(low.top());
			low.pop();
		}
		if(high.size()==low.size())
			cout<<0.5*(high.top()+low.top())<<endl;
		else{
			cout<<(high.size()>low.size()?high.top():low.top())<<endl;
		}
	}
}

int main(){
	string input = "1 2 3 4 5 6 7 8 9 10";
	istringstream ss(input);
	online_median(&ss);
}