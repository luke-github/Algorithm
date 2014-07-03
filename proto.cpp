#include <iostream>
#include <vector>
using namespace std;

void delete_duplicate(vector<int>& vec){
	int cur = 1;
	int tail= 1;
	for(;cur<vec.size();cur++){
		if(vec[cur]==vec[cur-1]){
			cur++;
		}else{
			vec[tail++]=vec[cur++];
		}
	}
}

int main(){
	vector<int> input = {1,3,4,5,3,7,4,9,5,6};
	sort(input.begin(),input.end());
	delete_duplicate(input);
	for(int x: input){
		cout<<x<<" ";
	}
}