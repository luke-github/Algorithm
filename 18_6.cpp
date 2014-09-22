#include <iostream>
#include <vector>
using namespace std;

bool has2sum(vector<int>& vec, int t){
	int j=0,k=vec.size()-1;
	while(j<=k){
		if(j+k==t){
			return true;
		}else if(j+k<t){
			j++;
		}else{
			k--;
		}
	}
	return false;
}

bool has3sum(vector<int>& vec,int t){
	sort(vec.begin(),vec.end());
	for(int x: vec){
		if(has2sum(vec,t-x)){
			return true;
		}
	}
	return false;
}

int main(){
	vector<int> input = {1,2,3,4,5};
	cout<<has3sum(input,20);
}
