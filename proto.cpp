#include <iostream>
#include <vector>
#include <unordered_set>
#include <tuple>
using namespace std;

struct HashTuple{
	size_t operator() (const tuple<int,int,int>& t){
		return hash<int>()(get<0>(t))^hash<int>()(get<1>(t))^hash<int>()(get<2>(t));
	}
};

bool match_sequence_handler(vector<vector<int>>& vec,vector<int>& s, int i, int j, int len, unordered_set<tuple<int,int,int>,HashTuple>* cache){
	if(len==s.size()){
		return true;
	}
	if(i<=0||i>=vec.size()||j<0||j>=vec[i].size()||cache->find({i,j,len})!=cache->end()){
		return false;
	}
	if((vec[i][j]==s[len]) && (match_sequence_handler(vec,s,i+1,j,len+1,cache)||
		match_sequence_handler(vec,s,i-1,j,len+1,cache)||
		match_sequence_handler(vec,s,i,j+1,len+1,cache)||
		match_sequence_handler(vec,s,i,j-1,len+1,cache))) {
		return true;
	}
	cache->emplace(i,j,len);
	return false;
}

bool match_sequence(vector<vector<int>>& vec, vector<int>& s){
	unordered_set<tuple<int,int,int>,HashTuple> cache;
	for(int i=0;i<vec.size();i++){
		for(int j=0;j<vec[i].size();j++){
			if(match_sequence_handler(vec,s,i,j,0,&cache)){
				return true;
			}
		}
	}
	return false;
}

int main(){
	vector<vector<int>> input = {{1,2,3},
								{4,5,6},
								{7,8,9}};
	vector<int> target = {1};
	cout<<match_sequence(input,target);							
}