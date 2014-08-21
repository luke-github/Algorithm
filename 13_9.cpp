#include <iostream>
#include <sstream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

pair<int,int> find_smallest_subarray(istringstream* sin, const vector<string>& q){
	list<int> loc;
	unordered_map<string,list<int>::iterator> dict;
	for(const string& s : q){
		dict.emplace(s,loc.end());
	}
	pair<int,int> res(-1,-1);
	int index=0;
	string s;
	while(*sin>>s){
		auto it = dict.find(s);
		if(it != dict.end()){
			if(it->second!=loc.end()){
				loc.erase(it->second);
			}
			loc.emplace_back(index);
			it->second = --loc.end();
		}

		if(loc.size()==q.size()&& ((res.first==-1&&res.second==-1) || (index - loc.front() < res.second - res.first))){
			res = {loc.front(),index};
		}

		index++;
	}
	return res;
}