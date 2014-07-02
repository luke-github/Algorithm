#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int cloest_pair(vector<string>& vec){
	unordered_map<string,int> hash;
	int cloest_dis = ((1<<31)-1);
	for(int i=0;i<vec.size();i++){
		auto it = hash.find(vec[i]);
		if(it!=hash.end()){
			cloest_dis = min(cloest_dis,i - it->second);
		}
		hash[vec[i]] = i;
	}
	return cloest_dis;
}
int main(){
	vector<string> input = {"a","b","c","d","a","d"};
	cout<<cloest_pair(input);
}