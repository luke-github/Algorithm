#include <iostream>
#include <vector>
using namespace std;

int bc_algorithm(int n, int k){
	int table[n+1][k+1];
	table[0][0]=1;
	for(int i=1;i<=n;i++){
		table[i][0]=1;
		for(int j=1;j<=i&&j<=k;j++){
			table[i][j]=table[i-1][j]+table[i-1][j-1];
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}
	return table[n][k];
}




int main(){
	cout<<bc_algorithm(5,3);
}