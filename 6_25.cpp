#include <iostream>
#include <vector>
using namespace std;

void rook_attack(vector<vector<int>>* vec){
	int m = vec->size();
	int n = (*vec)[0].size();
	bool has_first_row_zero = false;
	bool has_first_column_zero = false;

	for(int j=0;j<n;j++){
		if(!(*vec)[0][j]){
			has_first_row_zero = true;
			break;
		}
	}

	for(int i=0;i<m;i++){
		if(!(*vec)[i][0]){
			has_first_column_zero = true;
			break;
		}
	}

	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			if(!(*vec)[i][j]){
				(*vec)[i][0]=(*vec)[0][j]=0;
			}
		}
	}

	for(int i=1;i<m;i++){
		if(!(*vec)[i][0]){
			for(int j=1;j<n;j++){
				(*vec)[i][j]=0;
			}
		}
	}

	for(int j=1;j<n;j++){
		if(!(*vec)[0][j]){
			for(int i=1;i<m;i++){
				(*vec)[i][j]=0;
			}
		}
	}

	if(has_first_row_zero){
		for(int j=0;j<n;j++){
			(*vec)[0][j]=0;
		}
	}

	if(has_first_column_zero){
		for(int i=0;i<m;i++){
			(*vec)[i][0]=0;
		}
	}
}

int main(){
	
}