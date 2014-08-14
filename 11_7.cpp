#include <iostream>
#include <vector>
using namespace std;

vector<int> cal_bonus(vector<int>& rating){
	vector<int> res(rating.size(),1);
	for(int i=1;i<rating.size();i++){
		if(rating[i]>rating[i-1]){
			res[i]=res[i-1]+1;
		}
	}
	for(int i=rating.size()-2;i>=0;i--){
		if(rating[i]>rating[i+1]){
			res[i] = max(res[i],res[i+1]+1);
		}
	}
	return res;
}

int main(){
	vector<int> input = {300,400,500,200};
	auto res = cal_bonus(input);
	for(int x : res){
		cout<<x<<" ";
	}
}