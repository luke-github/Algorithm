#include <iostream>
#include <vector>
using namespace std;

struct item{
	int weight;
	int value;
};

int knapsack_algorithm(vector<item>& vec, int k){
	int res[vec.size()+1][k+1];
	for(int i=0;i<=vec.size();i++){
		for(int j=0;j<=k;j++){
			if(i==0){
				res[i][j]=0;
			}else{
				if(vec[i].weight>j){
					res[i][j]=res[i-1][j];
				}else{
					res[i][j]=max(res[i-1][j],res[i-1][j-vec[i-1].weight]+vec[i-1].value);
				}
			}
		}
	}
	return res[vec.size()][k];
}

int main(){
	vector<item> input = {{4,3},
						{2,4},
						{1,6},
						{5,7}};
	cout<<knapsack_algorithm(input,6);
}