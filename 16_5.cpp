#include <iostream>
#include <vector>
#include <complex>
using namespace std;

void power_set(vector<int>& vec){
	for(int i=0;i<(1<<vec.size());i++){
		int x = i;
		while(x){
			int tar =log2(x&~(x-1));
			cout<<vec[tar];
			if(x&=(x-1)){
				cout<<",";
			}
		}
		cout<<endl;
	}
}

int main(){
	vector<int> input = {1,2,3};
	power_set(input);
}