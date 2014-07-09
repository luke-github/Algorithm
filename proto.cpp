#include <iostream>
#include <vector>
using namespace std;

void permutation_handler(vector<int>* vec,int index,vector<vector<int>>* res){
	if(index==vec->size()){
		res->emplace_back(*vec);
		return;
	}
	for(int i=index;i<vec->size();i++){
		swap((*vec)[i],(*vec)[index]);
		permutation_handler(vec,index+1,res);
		swap((*vec)[i],(*vec)[index]);
	}
}

vector<vector<int>> permutation(vector<int> vec){
	vector<vector<int>> res;
	permutation_handler(&vec,0,&res);
	return res;
}
int main(){
	vector<int> input = {1,2,3,4,5};
	auto result = permutation(input);
	for(vector<int> v : result){
		for(int x : v){
			cout<<x<<" ";
		}
		cout<<endl;
	}
}