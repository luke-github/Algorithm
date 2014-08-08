#include <iostream>
#include <vector>
using namespace std;

void apply_sequence_fun(vector<int>* perm, vector<int>* vec){
	for(int i=0;i<vec->size();i++){
		if((*perm)[i]>=0){
			int a = i;
			int tmp = (*vec)[a];
			do{
				int next_a = (*perm)[a];
				int next_tmp = (*vec)[next_a];
				(*vec)[next_a] = tmp;
				(*perm)[a]-=vec->size();
				a = next_a;
				tmp = next_tmp;
			}while(a!=i);
		}
	}
}

int main(){
	vector<int> seq = {2,1,0,3};
	vector<int> input = {1,2,3,4};
	apply_sequence_fun(&seq,&input);
	for(auto x : input){
		cout<<x<<" ";
	}
}