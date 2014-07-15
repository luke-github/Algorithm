#include <iostream>
#include <vector>
using namespace std;

int max_trapped_algorithm(vector<int>& vec){
	int res = 0;
	int i=0,j=vec.size()-1;
	while(i<j){
		res = max(res,min(vec[i],vec[j])*(j-i));
		if(i<j){
			i++;
		}else if(i>j){
			j++;
		}else{
			i++;
			j++;
		}
	}
	return res;
}

int main(){
	vector<int> input={1,6,3,8,5,7,3,9};
	cout<<max_trapped_algorithm(input);
}