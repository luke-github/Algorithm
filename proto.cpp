#include <iostream>
#include <vector>
#include <deque>
using namespace std;


bool checkValid(vector<vector<int> >&sudo, int start_row, int end_row, int start_col, int end_col, int num);
bool checkSudo(vector<vector<int> >& sudo){
	for(int i=0;i<9;i++){
		if(checkValid(sudo,i,i+1,0,9,9)){
			return false;
		}
		if(checkValid(sudo,0,9,i,i+1,9)){
			return false;
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;i<3;j++){
			if(checkValid(sudo,3*i,3*(i+1),3*j,3*(j+1),3))
				return false;
		}
	}
	return true;

}

bool checkValid(vector<vector<int> >&sudo, int start_row, int end_row, int start_col, int end_col, int num){
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

int main(){

}

























































