#include <iostream>
#include <vector>
using namespace std;

int larger_than_search(vector<int>& vec, int k){
	int l=0,r=vec.size()-1,res=-1;
	while(l<=r){
		int m = (l+r)>>1;
		if(vec[m]>k){
			res = m;
			r=m-1;
		}else{
			l=m+1;
		}
	}
	return res;
}

int main(){
	vector<int> input = {1,3,5,7,9};
	cout<<larger_than_search(input,6);
}