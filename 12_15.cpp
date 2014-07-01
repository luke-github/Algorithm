#include <iostream>
#include <vector>
using namespace std;

pair<int,int> missing_and_duplicting(vector<int>& vec){
	int sum=0;
	int square_sum=0;
	for(int i=0;i<vec.size();i++){
		sum+=i-vec[i];
		square_sum+=i*i-vec[i]*vec[i];
	}
	return {(square_sum/sum+sum)/2,(square_sum/sum -  sum)/2};
}

int main(){
	vector<int> input {0,1,2,3,4,4,6,7,8,9};
	pair<int,int> result = missing_and_duplicting(input);
	cout<<result.first<<" "<<result.second;
}