#include<iostream>
#include<vector>
using namespace std;

int removeDuplicated(vector<int> &vec){
	int i=0;
	for(int j=1;j<vec.size();j++){
		if(vec[i]!=vec[j]){
			vec[++i]=vec[j];
		}
	}
	return i+1;
}

int main(){
	vector<int> input;
	input.push_back(1);
	input.push_back(2);
	input.push_back(3);
	input.push_back(3);
	input.push_back(3);
	input.push_back(3);
	cout<<removeDuplicated(input)<<endl;
	for(int x:input)
		cout<<x<<",";
}