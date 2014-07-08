#include <iostream>
#include <vector>
#include <array>
using namespace std;

vector<int> vec;

bool checker(int index){
	for(int i=0;i<index;i++){
		int diff = abs(vec[index]-vec[i]);
		if(diff == index-i || diff == 0){
			return false;
		}
	}
	return true;
}

void n_queen_algorithm(int n,int index){
	if(n==index){
		for(int x: vec){
			cout<<x<<" ";
		}
		cout<<endl;
		return;
	}
	for(int i=0;i<n;i++){
		vec[index]=i;
		if(checker(index)){
			n_queen_algorithm(n,index+1);
		}
	}
}


int main(){
	int n = 4;
	vec = vector<int>(n,0);
	n_queen_algorithm(n,0);
}