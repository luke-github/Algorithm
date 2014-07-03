#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> vec = {1, 2, 2, 3, 3, 2, 1, 1, 2};
	unique(vec.begin(),vec.end());
	for(int x : vec){
		cout<<x<<" ";
	}
}