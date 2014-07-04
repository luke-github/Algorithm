#include <iostream>
#include <vector>
using namespace std;

struct interval{
	int start;
	int end;
};

vector<interval> insert_interval(vector<interval>& vec, interval newInter){
	vector<interval> res;
	int i=0;

	while(i<vec.size()&&newInter.start>vec[i].end){
		res.emplace_back(vec[i]);		
		i++;
	}
	while(i<vec.size()&&newInter.end>=vec[i].start){
		newInter={min(newInter.start,vec[i].start),max(newInter.end,vec[i].end)};
		i++;
	}
	res.emplace_back(newInter);
	res.insert(res.end(),vec.begin()+i,vec.end());
	return res;
}

int main(){
	vector<interval> input = {{0,3},{4,6},{7,9},{11,13}};
	vector<interval> result = insert_interval(input,interval{5,9});
	for(interval x : result){
		cout<<x.start<<"-"<<x.end<<" ";
	}
}