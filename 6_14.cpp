#include<iostream>
#include<vector>
using namespace std;

void nextPermu(vector<int>& vec){
	int k=vec.size()-2;
	while((vec[k]>=vec[k+1])&&k>=0)
		k--;
	if(k==-1)
		return;
	int l;
	for(int i=k+1;i<vec.size();i++){
		if(vec[i]>vec[k])
			l=i;
		else
			break;
	}
	swap(vec[k],vec[l]);
	reverse(vec.begin()+k+1,vec.end());
}

int main(){
	vector<int> input;
	input.push_back(1);
	input.push_back(0);
	input.push_back(3);
	input.push_back(2);
	nextPermu(input);
	for(int m:input)
		cout<<m<<":";

}