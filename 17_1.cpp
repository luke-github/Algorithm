#include <iostream>
#include <vector>
using namespace std;

int combination_algorithm(int k,vector<int>& vec){
	vector<int> res(k+1,0);
	res[0]=1;
	for(int x : vec){
		for(int i=x;i<=k;i++){
			res[i] += res[i-x];
		}
	}
	return res[k];
}

int main(){
	vector<int> input = {2,3,7};
	cout<<combination_algorithm(12,input);
}