#include<iostream>
#include<vector>
using namespace std;

bool checker(vector<int> &vec){
	int reach=0, last_reach=0;
	for(int i=0;i<vec.size();i++){
		if(i>last_reach){
			if(last_reach==reach)
				return false;
			last_reach=reach;
		}
		reach=max(reach,i+vec[i]);
	}
	return true;
}

bool checker2(vector<int> &vec){
	int reach=vec[0];
	for(int i=1;i<vec.size();i++){
		if(i>reach)
			return false;
		reach=max(reach,i+vec[i]);
	}
	return true;
}

int main(){
	vector<int> input;
	input.push_back(3);
	input.push_back(3);
	input.push_back(1);
	input.push_back(0);
	input.push_back(2);
	input.push_back(0);
	input.push_back(1);
	cout<<checker(input)<<endl;
	cout<<checker2(input)<<endl;
}