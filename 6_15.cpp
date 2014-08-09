#include <iostream>
#include <vector>
using namespace std;

void rotate_array(int i, vector<int>* vec){
	i = i % vec->size();
	reverse(vec->begin(),vec->end());
	reverse(vec->begin(),vec->begin()+i);
	reverse(vec->begin()+i,vec->end());
}

int main(){
	vector<int> input = {1,2,3,4,5};
	rotate_array(2,&input);
	for(auto x: input){
		cout<<x<<" ";
	}
}