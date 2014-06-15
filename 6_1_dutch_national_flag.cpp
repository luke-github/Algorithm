#include<iostream>
#include<vector>
using namespace std;

template<class T>
void dutchNationalFlag(vector<T> &A, const int& pivot_index){
	T pivot = A[pivot_index];
	int smaller=0, equal=0, larger=A.size()-1;
	while(equal<larger){
		if(A[equal]<pivot){
			swap(A[equal++],A[smaller]);
		}
		else if(A[equal]==pivot){
			equal++;
		}
		else{
			swap(A[equal],A[larger--]);
		}
	}
}
