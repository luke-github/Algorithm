#include<iostream>
#include<vector>
using namespace std;

vector<int> adder(vector<int> array){
	array.back()++;
	for(int i=array.size()-1;i>0&&array[i]==10;i--){
		array[i]=0;
		array[i-1]++;
	}
	if(array[0]==10){
		array[0]=0;
		array.insert(array.begin(),1,1);
	}
	return array;
}

int main(){
	vector<int> vec;
	vec.push_back(9);
	vec.push_back(9);
	vec.push_back(9);
	vector<int> result = adder(vec);
	for(int m: result)
		cout<<m<<",";

}