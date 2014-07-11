#include <iostream>
#include <vector>
#include <array>
using namespace std;

int BC_algorithm(int n, int k){
	array<vector<int>,2> table = {vector<int>(k+1),vector<int>(k+1)};
	table[0][0]=1;
	for(int i=1;i<=n;i++){
		table[i&1][0]=1;
		for(int j=1;j<=i&&j<=k;j++){
			// cout<<(i&1)<<endl;
			table[i&1][j]=table[(i-1)&1][j]+table[(i-1)&1][j-1];
		}
	}
	for(auto x: table){
		for(auto y: x){
			cout<<y<<" ";
		}
		cout<<endl;
	}
	return table[n&1][k];
}

int BC_algorithm_2(int n, int k){
	int table[n+1][k+1];
	table[0][0]=1;
	for(int i=1;i<=n;i++){
		table[i][0]=1;
		for(int j=1;j<=k&&j<=i;j++){
			table[i][j]=table[i-1][j]+table[i-1][j-1];
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}
	return table[n][k];
}

int main(){
	// cout<<BC_algorithm(5,2)<<endl;
	cout<<BC_algorithm_2(4,2);
}