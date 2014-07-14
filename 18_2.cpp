#include <iostream>
#include <vector>
using namespace std;

int minimal_waiting_time(vector<int>& vec){
	sort(vec.begin(),vec.end());
	int total=0;
	for(int i=0;i<vec.size();i++){
		total += vec[i]*(vec.size()-(i+1));
	}
	return total;
}

int main(){
	vector<int> input={2,6,4,9};
	cout<<minimal_waiting_time(input);
}