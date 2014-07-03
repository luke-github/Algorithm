#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <set>
using namespace std;

pair<string,string> affinity_pair(ifstream* ifs){
	unordered_map<string,set<string>> hash;
	string page,user;
	while(*ifs>>page>>user){
		hash[page].emplace(user);
	}
	pair<string,string> res;
	int max_count = 0;
	for(auto a = hash.begin();a!=hash.end();a++){
		auto b=a;
		b++;
		for(;b!=hash.end();b++){
			vector<string> intersect_users;
			set_intersection(a->second.begin(),a->second.end(),
				b->second.begin(),b->second.end(),back_inserter(intersect_users));
			if(intersect_users.size()>max_count){
				max_count=intersect_users.size();
				res = {a->first,b->first};
			}
		}
	}
	return res;
}
int main(){
	ifstream is("metafile");
	pair<string,string> res = affinity_pair(&is);
	cout<<res.first<<" "<<res.second;
}