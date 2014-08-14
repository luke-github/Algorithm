#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class cmp{
public:
	cmp(double m) : m_(m) {};
	bool operator () (int a, int b) const {
		return fabs(a - m_)<fabs(b - m_);
	}

private:
	double m_;
};

double find_median(vector<int>* vec){
	int half = vec->size()/2;
	nth_element(vec->begin(),vec->begin()+half,vec->end());
	if(vec->size()&1){
		return (*vec)[half];
	}else{
		int x = (*vec)[half];
		nth_element(vec->begin(),vec->begin()+half-1,vec->end());
		return (0.5)*(x+(*vec)[half-1]);
	}
}

vector<int> kth_element(vector<int>& vec, int k){
	nth_element(vec.begin(),vec.begin()+k-1,vec.end(),cmp(find_median(&vec)));
	return {vec.begin(),vec.begin()+k};
}

int main(){
	vector<int> input = {1,2,3,4,5,6,7,8,9};
	auto res = kth_element(input,5);
	for(int x : res){
		cout<<x<<" ";
	}
}