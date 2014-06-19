#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void printAlgorithm(vector<vector<int> >&vec, int offset);


void printSpiral(vector<vector<int> >&vec){
	for(int offset=0;offset<ceil(0.5*vec.size());offset++){
		printAlgorithm(vec,offset);
	}
}

void printAlgorithm(vector<vector<int> >&vec, int offset){
	if(((offset*2)+1)==vec.size()){
		cout<<vec[offset][offset];
	}else{
		for(int i=offset;i<vec.size()-offset-1;i++)
			cout<<vec[offset][i];
		for(int i=offset;i<vec.size()-offset-1;i++)
			cout<<vec[i][vec.size()-offset-1];
		for(int i=vec.size()-offset-1;i>offset;i--)
			cout<<vec[vec.size()-offset-1][i];
		for(int i=vec.size()-offset-1;i>offset;i--)
			cout<<vec[offset][i];
	}
}

int main(){

}