#include <iostream>
#include <vector>
using namespace std;

int enhance_binary_search(vector<int>& vec, int k){
	int l=0,r=vec.size()-1,res=-1;
	while(l<=r){
		int m = (l+r)/2;
		if(vec[m]==k){
			res=m;
			r=m-1;
		}else if(k>vec[m]){
			l=m+1;
		}else{
			r=m-1;
		}
	}
	return res;
}

int main(){
	vector<int> input = {1,2,3,6,6,6,6,6,7,8};
	cout<<enhance_binary_search(input,6);
}