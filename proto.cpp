#include <iostream>
#include <vector>
using namespace std;

vector<int> common_element(vector<int>& a, vector<int>& b){
	vector<int> res;
	int i=0,j=0;
	while(i<a.size()&&j<b.size()){
		if(a[i]==b[j]&&(i==0||a[i]!=a[i-1])){
			res.emplace_back(a[i]);
			i++;
			j++;
		}else if(a[i]>b[j]){
			j++;
		}else{
			i++;
		}
	}
	return res;
}


int main(){
	vector<int> input1 = {1,2,3,4,5,6};
	vector<int> input2 = {1,5,6,7,8,9};
	vector<int> result = common_element(input1,input2);
	for(int x : result){
		cout<<x<<" ";
	}
}