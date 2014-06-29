#include <iostream>
#include <vector>
using namespace std;

int search_value_index_equal(vector<int>& vec){
	int l=0,r=vec.size()-1,res=-1;
	while(l<=r){
		int m = (l+r)>>1;
		int val = vec[m]-m;
		if(val==0){
			return m;
		}else if(val>0){
			r=m-1;
		}else{
			l=m+1;
		}
	}
	return res;
}
