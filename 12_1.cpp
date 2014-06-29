#include <iostream>
#include <vector>
using namespace std;

int enhanced_binary_search(vector<int>& vec, int k){
	int l=0,r=vec.size()-1,result=-1;
	while(l<=r){
		int m = (l+r)>>1;
		if(vec[m]==k){
			result=m;
			r=m-1;
		}else if(vec[m]<k){
			l=m+1;
		}else{
			r=m-1;
		}
	}
	return result;
}

int main(){
	vector<int> input = {1,2,3,6,6,6,6,6,7,8};
	cout<<enhanced_binary_search(input,6);
}