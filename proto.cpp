#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int merge_algo(vector<int>& vec, int start, int mid, int end){
	vector<int> sorted_vec;
	int num_invert=0;
	int left_start = start, right_start = mid;
	while(left_start<mid&&right_start<end){
		if(vec[left_start]<vec[right_start]){
			sorted_vec.emplace_back(vec[left_start++]);
		}else{	
			num_invert += mid - left_start;
			sorted_vec.emplace_back(vec[right_start++]);
		}
	}
	copy(vec.begin()+left_start,vec.begin()+mid,back_inserter(sorted_vec));
	copy(vec.begin()+right_start,vec.begin()+end,back_inserter(sorted_vec));
	copy(sorted_vec.begin(),sorted_vec.end(),vec.begin()+start);
	return num_invert;
}

int count_inversion_algo(vector<int>&vec, int start, int end){
	if(end -  start <= 1){
		return 0;
	}else{
		int mid =  (start+end)/2;
		return count_inversion_algo(vec,start,mid) + count_inversion_algo(vec,mid,end) + merge_algo(vec,start,mid,end);
	}
}

int count_inversion(vector<int>& vec){
	return count_inversion_algo(vec,0,vec.size());
}