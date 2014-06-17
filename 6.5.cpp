#include<iostream>
#include<vector>
using namespace std;

int removeElement(vector<int> &vec, int k){
	int m=0;
	for(int i=0;i<vec.size();i++){
		if(vec[i]!=k){
			vec[m++]=vec[i];
		}
	}
	return m;
}


int main(){
	vector<int> input;
	input.push_back(1);
	input.push_back(2);
	input.push_back(3);
	input.push_back(3);
	input.push_back(5);
	input.push_back(6);
	cout<<removeElement(input,3)<<endl;
	for(int x:input)
		cout<<x<<",";
}