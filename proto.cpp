#include <iostream>
#include <complex>
#include <vector>
using namespace std;

void super_set(vector<int>& vec){
	for(int i=0;i<(1<<vec.size());i++){
		int x=i;
		while(x){
			int m = log2(x&(~(x-1)));
			cout<<vec[m];
			if(x&=(x-1)){
				cout<<",";
			}
		}
		cout<<endl;
	}
}

int main(){
	vector<int> input = {1,2,3,4};
	super_set(input);
}