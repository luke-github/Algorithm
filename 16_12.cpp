#include <iostream>
#include <vector>
using namespace std;

int combination_without_permutation(int n, vector<int>& vec){
	vector<int> res(n+1,0);
	res[0]=1;
	for(int x : vec){
		for(int i=x;i<=n;i++){
			res[i] += res[i-x];
		}
	}
	return res[n];
}

int combination_with_permutation(int n, vector<int>& vec){
	vector<int> res(n+1,0);
	res[0]=1;
	for(int i=0;i<=n;i++){
		for(int x : vec){
			if(i>=x){
				res[i] += res[i-x];
			}
		}
	}
	return res[n];
}


int main(){
	vector<int> input = {2,3,7};
	cout<<combination_without_permutation(12,input)<<endl;
	cout<<combination_with_permutation(12,input)<<endl;
}