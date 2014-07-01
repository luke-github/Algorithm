#include <iostream>
#include <vector>
#include <random>
using namespace std;
int partition(int left, int right, int pivot, vector<int>* v);

int kth_greatest(vector<int>& vec,int k){
	int left=0,right=vec.size()-1;
	while(left<=right){
		default_random_engine gen((random_device())());
		uniform_int_distribution<int> dis(left,right);
		int p = partition(left,right,dis(gen),&vec);
		if(p==k-1){
			return vec[p];
		}else if(p>k-1){
			right=p-1;
		}else{
			left = p+1;
		}
	}
	return -1;
}

int partition(int left, int right, int pivot, vector<int>* v){
	int larger_pointer=left;
	swap((*v)[pivot],(*v)[right]);
	for(int i=left;i<right;i++){
		if((*v)[i]>(*v)[right]){
			swap((*v)[i],(*v)[larger_pointer++]);
		}
	}
	swap((*v)[right],(*v)[larger_pointer]);
	return larger_pointer;
}

int main(){
	vector<int> input = {4,3,2,6,7,1,5};
	cout<<kth_greatest(input,1);
}