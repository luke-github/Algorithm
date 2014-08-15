#include <iostream>
#include <vector>
using namespace std;

bool sorted_array_search_algorithm(vector<vector<int>>& vec, int k){
	int r=0, c=vec[0].size()-1;
	while(r<vec.size()&&c>=0){
		if(vec[r][c]==k){
			return true;
		}else if(vec[r][c]>k){
			c--;
		}else{
			r++;
		}
	}
	return false;
}

int main(){

}