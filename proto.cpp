#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> vec = {1,3,4,2,3,6,7,5,4,3,2,3,4};
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	for(int x:vec){
		cout<<x<<" ";
	}
}