#include <iostream>
#include <vector>
using namespace std;

void merge_sort(int a[], int b[], int m, int n){
	int len_a=m-1,len_b=n-1,length=m+n-1;
	while(len_a>=0&&len_b>=0){
		a[length--]=a[len_a]>b[len_b]?a[len_a--]:b[len_b--];
	}
	while(len_b>=0){
		a[length--]=b[len_b--];
	}
}

int main(){
	int input1[5] = {5,7,9};
	int input2[2] = {6,8};
	merge_sort(input1,input2,3,2);
	for(int x: input1)
		cout<<x<<" ";
}