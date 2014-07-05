#include <iostream>
#include <vector>
using namespace std;

void sort_vector(vector<int>& vec){
	sort(vec.begin(),vec.end());
}

int main(){
	vector<int> input = {1,3,2,4,5};
	sort_vector(input);
	for(int x : input){
		cout<<x<<" ";
	}
}