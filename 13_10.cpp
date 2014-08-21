#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
using namespace std;

pair<int,int> sequentially_smallest_subarray(vector<string> A, vector<string> Q){
	unordered_map<string,int> K;
	vector<int> L(Q.size(),-1), D(Q.size(),numeric_limits<int>::max());

	for(int i=0;i<Q.size();i++){
		K.emplace(Q[i],i);
	}

	pair<int,int> res(-1,A.size());
	for(int i=0;i<A.size();i++){
		auto it = K.find(A[i]);
		if(it != K.end()){
			if(it->second == 0){
				D[0]=1;
			}
			else if(D[it->second - 1]!= numeric_limits<int>::max()){
				D[it->second] = i - L[it->second - 1] + D[it->second - 1];
			}
			L[it->second] = i;

			if(it->second == Q.size()-1 && D.back() < res.second - res.first +1){
				res = {i - D.back() + 1, i};
			}
		}
	}
	return res;
}