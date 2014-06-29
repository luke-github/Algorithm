#include <iostream>
#include <vector>
using namespace std;

int smallest_search(vector<int>& vec){
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
int main(){
	vector<int> input = {4,5,6,7,8,9,10,10,10,10,10,1,2,2,2,2,2,3};
	cout<<smallest_search(input);
}