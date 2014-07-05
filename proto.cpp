#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct Interval{
	int left,right;
};

struct leftCmp{
	bool operator () (const Interval* a, const Interval* b) const{
		return a->left!=b->left ? a->left < b->left : a->right < b->right;
	}
};

struct rightCmp{
	bool operator () (const Interval* a, const Interval* b) const{
		return a->right!=b->right ? a->right < b->right : a->left < b->left;
	}
};

vector<int> minimal_visits(vector<Interval>& vec){
	vector<int> res;
	set<const Interval*, leftCmp> L;
	set<const Interval*, rightCmp> R;
	for(Interval x: vec){
		L.emplace(&x);
		R.emplace(&x);
	}
	while(!L.empty()&&!R.empty()){
		int b = (*R.cbegin())->right;
		auto it = L.cbegin();
		res.emplace_back(b);
		while(it!=L.cend()&&(*it)->left<=b){
			R.erase(*it);
			L.erase(it++);
		}
	}
	return res;
}