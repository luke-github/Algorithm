#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct Interval{
	int left,right;
};

struct leftComp{
	bool operator () (const Interval& a,const Interval& b) const{
		return a.left!=b.left ? a.left<b.left : a.right<b.right;
	}
};

struct rightComp{
	bool operator () (const Interval&a,const Interval& b) const{
		return a.right!=b.right ? a.right < b.right : a.left<b.left;
	}
};

vector<int> minimal_visits(vector<Interval>& vec){
	set<const Interval, leftComp> L;
	set<const Interval, rightComp> R;
	for(Interval x: vec){
		L.emplace(x);
		R.emplace(x);
	}
	vector<int> res;
	while(!L.empty()&&!R.empty()){
		int b = R.cbegin()->right;
		res.emplace_back(b);
		auto it = L.cbegin();
		while(it!=L.cend()&&it->left<=b){
			R.erase(*it);
			L.erase(it++);
		}
	}
	return res;
}