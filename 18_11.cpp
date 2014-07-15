#include <iostream>
#include <vector>
using namespace std;

int max_trapped_vol_algorithm(vector<int>& height){
	int max_result = 0;
	int i=0,j=height.size()-1;
	while(i<j){
		max_result = max(max_result,min(height[i],height[j])*(j-i));
		if(i<j){
			i++;
		}else if(i>j){
			j++;
		}else{
			i++;
			j++;
		}
	}
	return max_result;
}

int main(){
	vector<int> input={1,6,3,8,5,7,3,9};
	cout<<max_trapped_vol_algorithm(input);
}