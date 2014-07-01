#include <iostream>
#include <vector>
#include <random>
using namespace std;

int partition(int left, int right, int pivot, vector<int>* v);

int kth_greatest_value(vector<int>& vec, int k){
	int left=0,right=vec.size()-1;
	while(left<=right){
		default_random_engine gen((random_device())());
		uniform_int_distribution<int> dis(left,right);
		int position = partition(left,right,dis(gen),&vec);
		if(position==k-1){
			return vec[position];
		}else if(position>k-1){
			right = position -1;
		}else{
			left = position+1;
		}
	}
	throw invalid_argument("no result");
}

int partition(int left, int right, int pivot, vector<int>* v){
	int pivot_value = (*v)[pivot];
	swap((*v)[pivot],(*v)[right]);
	int larger_index = left;
	for(int i=left;i<right;i++){
		if((*v)[i]>pivot_value){
			swap((*v)[i],(*v)[larger_index++]);
		}
	}
	swap((*v)[right],(*v)[larger_index]);
	return larger_index;
}

int main(){
	vector<int> input = {9,8,7,6,5,4,3,2,1};
	cout<<kth_greatest_value(input,1);
}