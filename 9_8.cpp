#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
using namespace std;

vector<pair<int,int> > sunset_function(istringstream* sin){
	vector<pair<int,int> > stk;
	int index=0;
	int height;
	while(*sin >> height){
		while(!stk.empty()&&height>=stk.back().second){
			stk.pop_back();
		}
		stk.emplace_back(index++,height);
	}
	return stk;
}

int main(){
	string input = "1 2 3 4 5 6 5 4 3";
	istringstream ssinput(input);
	vector<pair<int,int> > result = sunset_function(&ssinput);
	for(int i=0;i<result.size();i++){
		cout<<result[i].first<<":"<<result[i].second<<endl;
	}
}