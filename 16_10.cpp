#include <iostream>
#include <vector>
#include <complex>
using namespace std;

bool is_valid_added(int i, int j, int val, vector<vector<int>>& A){
	for(int k=0;k<A.size();k++){
		if((val==A[i][k])||(val==A[k][j])){
			return false;
		}
	}
	int region_size = sqrt(A.size());
	int row = i/region_size;
	int col = j/region_size;
	for(int a=0;a<region_size;a++){
		for(int b=0;b<region_size;b++){
			if(A[row*region_size+a][col*region_size+b]==val){
				return false;
			}
		}
	}
	return true;
}

bool sudoku_handler(int i,int j,vector<vector<int>>* A){
	if(i==A->size()){
		i=0;
		if(++j==(*A)[i].size()) {
			return true;
		}
	}
	if((*A)[i][j]!=0){
		return sudoku_handler(i+1,j,A);
	}
	for(int val=1;val<=A->size();val++){
		if(is_valid_added(i,j,val,*A)){
			(*A)[i][j]=val;
			if(sudoku_handler(i+1,j,A)){
				return true;
			}
		}
	}
	(*A)[i][j]=0;
	return false;
}

void sudoku(vector<vector<int>>& vec){
	if(sudoku_handler(0,0,&vec)){
		cout<<"success"<<endl;;
	}else{
		cout<<"false"<<endl;
	}
	for(int i=0;i<9;i++){
		if(i%3==0&&i!=0){
			cout<<"-----------------------"<<endl;
		}
		for(int j=0;j<9;j++){
			cout<<vec[i][j]<<" ";
			if((j+1)%3==0&&j!=0){
				cout<<"| ";
			}
		}
		cout<<endl;
	}
}

int main(){
	vector<vector<int>> input(9,vector<int>(9,0));
	// input[1][2]=8;
	// input[2][3]=3;
	// cout<<input.size();
	sudoku(input);
}