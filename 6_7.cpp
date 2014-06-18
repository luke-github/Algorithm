#include<iostream>
#include<vector>
using namespace std;

int findFristMissing(vector<int> &A){
	int i=0;
	while(i<A.size()){
		if(A[i]>0&&A[i]<A.size()&&A[A[i]-1]!=A[i]&&A[i]!=i+1){
			swap(A[i],A[A[i]-1]);
		}else{
			i++;
		}
	}
	for(int i=0;i<A.size();i++){
		if(A[i]!=i+1){
			return i+1;
		}
	}
	return A.size()+1;
}

int main(){
	vector<int> input;
	input.push_back(2);
	input.push_back(3);
	input.push_back(10);
	input.push_back(5);
	input.push_back(7);
	cout<<findFristMissing(input)<<endl;	
	
}