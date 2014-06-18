#include <iostream>
#include <vector>
#include <deque>
using namespace std;

bool has_duplicate(const vector<vector<int> >& sudo, int start_row, int end_row, int start_col, int end_col, int num){
	deque<bool> checker(num+1,false);
	for(int i=start_row;i<end_row;i++){
		for(int j=start_col;j<end_col;j++){
			if(sudo[i][j]!=0 && checker[sudo[i][j]]){
				return true;
			}
			checker[sudo[i][j]]=true;
		}
	}
	return false;
}

bool checkSudo(const vector<vector<int> > & sudo){
	// check row first
	for(int i=0;i<9;i++){
		if(has_duplicate(sudo,i,i+1,0,9,9)){
			return false;
		}
	}
	// check col next
	for(int i=0;i<9;i++){
		if(has_duplicate(sudo,0,9,i,i+1,9)){
			return false;
		}
	}
	// check contained small matrix
	for(int i=0;i<3;i++){
		for(int j=0;i<3;j++){
			if(has_duplicate(sudo,3*i,3*(i+1),3*j,3*(j+1),9)){
				return false;
			}
		}
	}
	return true;
}



int main(){

}