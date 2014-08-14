#include <iostream>
#include <vector>
using namespace std;

vector<int> fair_bonus(const vector<int>& vec){
	vector<int> res(vec.size(),1);
	for(int i=0;i<vec.size()-1;i++){
		if(vec[i+1]>vec[i]){
			res[i+1]=res[i]+1;
		}
	}
	for(int i=vec.size()-2;i>=0;i--){
		if(vec[i]>vec[i+1]){
			res[i] = max(res[i],res[i+1]+1);
		}
	}
	return res;
}

int main(){
		vector<int> input = {300,400,500,200};
	auto res = fair_bonus(input);
	for(int x : res){
		cout<<x<<" ";
	}
}