#include <iostream>
#include <vector>
#include <cstddef>
using namespace std;

vector<vector<int> > generate_pascal_triangle(int n){
	if(n<=0){
		return {};
	}
	vector<vector<int> > result;
	result.push_back(vector<int>{1});
	for(int i=1;i<n;i++){
		vector<int> current_row;
		current_row.push_back(1);
		for(int j=1;j<i;j++){
			current_row.push_back(result.back()[j-1]+result.back()[j+1]);
		}
		current_row.push_back(1);
		result.push_back(current_row);
	}
	return result;
}

int main(){

}