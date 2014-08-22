#include <iostream>
#include <vector>
using namespace std;

int unconstructible_number(vector<int> vec){
	sort(vec.begin(),vec.end());
	int sum = 0;
	for(int x: vec){
		if(x > sum+1){
			break;
		}
		sum += x;
	}
	return sum+1;
}

int main(){
	vector<int> input = {1,1,2,5,10};
	cout<<unconstructible_number(input);
}