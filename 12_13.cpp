#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int kth_largest_element(istringstream* sin, int k){
	vector<int> vec;
	int x;
	while(*sin>>x){
		vec.emplace_back(x);
		if(vec.size()==(k<<1)-1){
			nth_element(vec.begin(),vec.begin()+k-1,vec.end(),greater<int>());
			vec.resize(k);
		}
	}
	nth_element(vec.begin(),vec.begin()+k-1,vec.end(),greater<int>());
	return vec[k-1];
}

int main(){
	string input = "9 8 7 6 5 4 3 2 1";
	istringstream ss(input);
	cout<<kth_largest_element(&ss,5);
}