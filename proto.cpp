#include <iostream>
#include <vector>
using namespace std;

struct Interval{
private:
	struct Endpoint{
		bool isClose;
		int val;
	};
public:
	Endpoint left, right;
	bool operator < (const Interval& s) const {
		return left.val!=s.left.val ? left.val < s.left.val : left.isClose&&!s.left.isClose;
	}
};

vector<Interval> union_intervals(vector<Interval>& vec){
	vector<Interval> res;
	sort(vec.begin(),vec.end());
	Interval cur = vec.front();
	for(int i=1;i<vec.size();i++){
		if((vec[i].left.val<cur.right.val)||((vec[i].left.val==cur.right.val)&&(vec[i].left.isClose||cur.right.isClose))){
			if((vec[i].right.val>cur.right.val)||((vec[i].right.val==cur.right.val)&&(vec[i].right.isClose||cur.right.isClose))){
				cur.right = vec[i].right;
			}
		}else{
			res.emplace_back(cur);
			cur = vec[i];
		}
	}
	res.emplace_back(cur);
	return res;
}