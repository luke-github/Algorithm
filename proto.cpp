#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<pair<int,int>> sunset_solution(istringstream* sin){
	vector<pair<int,int>> vec;
	int height;
	int index=0;
	while(*sin>>height){
		while(!vec.empty()&&height>=vec.back().second){
			vec.pop_back();
		}
		vec.emplace_back(index++,height);
	}
	return vec;
}

int main(){
	string input = " 1 2 3 4 5 6 5 4 3";
	istringstream ss(input);
	vector<pair<int,int>> result = sunset_solution(&ss);
	for(int i=0;i<result.size();i++)
		cout<<result[i].first<<" "<<result[i].second<<endl;
}