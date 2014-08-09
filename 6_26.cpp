#include <iostream>
#include <vector>
using namespace std;

int celebrity_algo(vector<vector<bool>>& vec){
	int i=0,j=1;
	while(j<vec.size()){
		if(vec[i][j]){
			i=j++;
		}else{
			j++;
		}
	}
	return i;
}

// this algorithm is too simple to understand clearly.