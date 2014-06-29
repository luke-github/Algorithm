#include <iostream>
#include <vector>
using namespace std;

int search_smallest(vector<int>& vec){
	int l=0,r=vec.size()-1;
	while(l<r){
		int m = (l+r)>>1;
		if(vec[m]>vec[r]){
			l=m+1;
		}else{
			r=m;
		}
	}
	return vec[l];
}