#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;

bool checker(int index){
	for(int i=0;i<index;i++){
		int diff = abs(vec[index]-vec[i]);
		if(diff == 0 || diff == index - i){
			return false;
		}
	}
	return true;
}

void n_queen_algorithm(int n, int index){
	if(n==index){
		for(int x : vec){
			cout<<x<<"->";
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
	int n = 8;
	vec = vector<int>(n,0);
	n_queen_algorithm(n,0);
}