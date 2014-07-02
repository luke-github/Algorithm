#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int cloest_pair(vector<string>& vec){
	int cloest_dist = (1<<31)-1;
	unordered_map<string,int> hash;
	for(int i=0;i<vec.size();i++){
		auto it = hash.find(vec[i]);
		if(it!=hash.end()){
			cloest_dist=min(cloest_dist,i - it->second);
		}
		hash[vec[i]] = i;
	}
	return cloest_dist;
}
int main(){
	
}