#include <iostream>
#include <vector>
using namespace std;

int max_collection_algorithm(vector<vector<int>> vec){
	for(int i=0;i<vec.size();i++){
		for(int j=0;j<vec[i].size();j++){
			vec[i][j] += max((i<1?0:vec[i-1][j]),(j<1?0:vec[i][j-1]));
		}
	}
	return vec.back().back();
}

int main(){
	vector<vector<int>> input(3,vector<int>(3,0));
	input[1][1]=3;
	input[1][0]=6;
	input[2][0]=9;
	input[0][2]=16;
	for(auto x : input){
		for(auto y: x){
			cout<<y<<" ";
		}
		cout<<endl;
	}
	cout<<max_collection_algorithm(input)<<endl;


}