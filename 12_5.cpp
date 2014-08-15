#include <iostream>
#include <vector>
using namespace std;

int unknown_boundary_search(vector<int>& vec, int k){
	int p = 0;
	while(true){
		int val = vec[(1<<p)-1];
		if(val==k){
			return (1<<p)-1;
		}else if(val > k){
			break;
		}
		p++;
	}
	int left = max(0,1<<(p-1)), right = (1<<p)-2;
	while(left<=right){
		int mid = (left+right)/2;
		int val = vec[mid];
		if(val==k){
			return mid;
		}else if(val>k){
			right = mid-1;
		}else{
			left = mid+1;
		}
	}
	return -1;
}

int main(){
	vector<int> input = {1,2,3,4,5,6,7,8,9};
	cout<<unknown_boundary_search(input,8);
}