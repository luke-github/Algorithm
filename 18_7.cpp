#include <iostream>
#include <vector>
using namespace std;

int ample_city_algorithm(vector<int>& G, vector<int> &D){
	int carry = 0;
	pair<int,int> res={0,0};
	for(int i=1;i<G.size();i++){
		carry += G[i-1]-D[i-1];
		if(carry<res.second){
			res={i,carry};
		}
	}
	return res.first;
}

int main(){
	
}