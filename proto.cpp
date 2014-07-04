#include <iostream>
#include <vector>
using namespace std;

struct interval{
	int start;
	int end;
};

vector<interval> insert_interval(vector<interval>& vec, interval new_interval){
	int i=0;
	vector<interval> res;
	while(i<vec.size()&&new_interval.start>vec[i].end){
		res.emplace_back(vec[i]);
		i++;
	}
	while(i<vec.size()&&new_interval.end>=vec[i].start){
		new_interval = {min(new_interval.start,vec[i].start),max(new_interval.end,vec[i].end)};
		i++;
	}
	res.emplace_back(new_interval);
	res.insert(res.end(),vec.begin()+i,vec.end());
	return res;
}
int main(){
	vector<interval> input = {{0,3},{4,6},{7,9},{11,13}};
	vector<interval> result = insert_interval(input,interval{14,16});
	for(interval x : result){
		cout<<x.start<<"-"<<x.end<<" ";
	}
}