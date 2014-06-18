#include<iostream>
#include<vector>
#include<random>
using namespace std;

void kSamples(vector<int>& vec, int k){
	default_random_engine gen((random_device())());
	for(int i=0;i<k;i++){
		uniform_int_distribution<int> dis(i,vec.size()-1);
		swap(vec[i],vec[dis(gen)]);
	}
	vec.resize(k);
}

int main(){
	vector<int> input;
	input.push_back(1);
	input.push_back(2);
	input.push_back(3);
	input.push_back(4);
	input.push_back(5);
	kSamples(input,2);
	for(int m:input)
		cout<<m<<":";

}