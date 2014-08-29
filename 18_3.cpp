#include <iostream>
#include <vector>
using namespace std;

int max_containing(vector<int>& vec){
	int sum = 0;
	int left = vec.front();
	int max = distance(vec.begin(),max_element(vec.begin(),vec.end()));
	for(int i=1;i<max;i++){
		if(left<vec[i]){
			left = vec[i];
		}else{
			sum += left - vec[i];
		}
	}
	int right = vec.back();
	for(int i=vec.size()-2;i>max;i--){
		if(right<vec[i]){
			sum += right - vec[i];
		}else{
			right = vec[i];
		}
	}
	return sum;
}