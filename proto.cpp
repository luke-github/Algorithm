#include <iostream>
#include <vector>
using namespace std;

void flip_algorithm(vector<vector<bool>>* vec, int x, int y){
	bool color = (*vec)[x][y];
	(*vec)[x][y] = !(*vec)[x][y];
	int shift[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
	for(auto m : shift){
		int nx = x+m[0],ny=y+m[1];
		if(nx>=0 && nx<vec->size() && ny>=0 && ny<(*vec)[nx].size() && (*vec)[nx][ny]==color){
			flip_algorithm(vec,nx,ny);
		}
	}
}

int main(){
	vector<vector<bool>> input(5,vector<bool>(5,0));
	input[0][1]=1;
	input[0][0]=1;
	input[1][0]=1;
	input[1][1]=1;
	for(auto x: input){
		for(auto y : x){
			cout<<y<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	flip_algorithm(&input,3,3);
		for(auto x: input){
		for(auto y : x){
			cout<<y<<" ";
		}
		cout<<endl;
	}
}