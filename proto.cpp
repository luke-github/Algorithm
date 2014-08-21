#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

pair<int,int> find_smallest_subarray(istringstream* sin, const vector<string>& q){
	list<int> loc;
	unordered_map<string,list<int>::iterator> dict;
	for(const string& s: q){
		dict.emplace(s,loc.end());
	}
	int index = 0;
	pair<int,int> res(-1,-1);
	string s;
	while(*sin>>s){
		auto it = dict.find(s);
		if(it != dict.end()){
			if(it->second != loc.end()){
				loc.erase(it->second);
			}
			loc.emplace_back(index);
			it->second = --loc.end();
		}
		// check if program finishes
		if(loc.size()==q.size()&& ((res.first==-1 && res.second==-1) || (index - loc.front()< res.second - res.first))){
			res = {loc.front(),index};
		}
		index++;
	}
	return res;
}