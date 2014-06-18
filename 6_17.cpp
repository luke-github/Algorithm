#include<iostream>
#include<random>
#include<vector>
using namespace std;

void randomPermu(vector<int>& vec){
	default_random_engine gen((random_device())());
	for(int i=0;i<vec.size();i++){
		uniform_int_distribution<int> dist(i,vec.size()-1);
		swap(vec[i],vec[dist(gen)]);
	}
}
int main(){
	vector<int> input;
	input.push_back(1);
	input.push_back(2);
	input.push_back(3);
	input.push_back(4);
	input.push_back(5);
	randomPermu(input);
	for(int m:input)
		cout<<m<<":";
}