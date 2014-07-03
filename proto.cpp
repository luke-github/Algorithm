#include <iostream>
#include <vector>
using namespace std;

void merge_sort(int a[],int b[],int m,int n){
	int length = m+n-1;
	int i=m-1;
	int j=n-1;
	while(i>=0&&j>=0){
		a[length--]=a[i]>b[j]?a[i--]:b[j--];
	}
	while(j>=0){
		a[length--]=b[j--];
	}
}