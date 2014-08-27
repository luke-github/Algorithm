#include <iostream>
#include <vector>
using namespace std;

int max_floor_handler(int c, int d, vector<vector<int>>* F){
	if(c==0 || d==0){
		return 0;
	}else if(c==1){
		return d;
	}else{
		if((*F)[c][d]==-1){
			(*F)[c][d] = max_floor_handler(c-1,d-1,F)+1+max_floor_handler(c,d-1,F);
		}
		return (*F)[c][d];
	}
}

int max_floor(int c, int d){
	vector<vector<int>> F(c+1,vector<int>(d+1,-1));
	return max_floor_handler(c,d,&F);
}