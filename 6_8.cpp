#include<iostream>
#include<vector>
using namespace std;

int findCapacity(vector<int>& vec){
	int capacity=0;
	int minHeight = ~(1<<31);
	for(int h:vec){
		capacity = max(capacity,h - minHeight);
		minHeight = min(minHeight,h);
	}
	return capacity;
}
int main(){

}