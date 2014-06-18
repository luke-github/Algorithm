#include <iostream>
#include <iterator>
#include <vector>
#include <random>
using namespace std;

double non_uniform(vector<double>& T, vector<double>& P){
	default_random_engine gen((random_device())());
	uniform_real_distribution<double> dist (0.0,1.0);
	vector<double> new_P;
	new_P.push_back(0);
	partial_sum(P.begin(),P.end(),back_inserter(new_P));
	auto it = upper_bound(new_P.begin(),new_P.end(),dist(gen));
	return T[distance(new_P.begin(),it)-1];
}

int main(){
	vector<double> input;
	input.push_back(1);
	input.push_back(2);
	input.push_back(3);
	input.push_back(4);
	vector<double> pro;
	pro.push_back(0.1);
	pro.push_back(0.3);
	pro.push_back(0.4);
	pro.push_back(0.2);
	cout<<non_uniform(input,pro);
}