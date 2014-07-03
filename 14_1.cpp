#include <iostream>
#include <vector>
using namespace std;

vector<int> common_element(vector<int>& A,vector<int>& B){
	vector<int> res;
	int i=0,j=0;
	while(i<A.size()&&j<B.size()){
		if(A[i]==B[j]&&(i==0||A[i]!=A[i-1])){
			res.emplace_back(A[i]);
			i++,j++;
		}else if(A[i]<B[j]){
			i++;
		}else{
			j++;
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