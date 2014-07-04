#include <iostream>
#include <vector>
using namespace std;

struct interval{
	int start;
	int end;
};

struct endpoint{
	bool operator < (const endpoint& e) const {
		return time!=e.time ? time < e.time : (isStart&&!e.isStart);
	}
	int time;
	bool isStart;
};

int max_overlap(vector<interval>& vec){
	int max_counter = 0;
	vector<endpoint> points;
	for(interval x : vec){
		points.emplace_back(endpoint{x.start,true});
		points.emplace_back(endpoint{x.end,false});
	}
	sort(points.begin(),points.end());
	int counter=0;
	for(const endpoint p: points){
		if(p.isStart){
			max_counter = max(max_counter,++counter);
		}else{
			counter--;
		}
	}
	return max_counter;
}

int main(){
	vector<interval> input = {{1,3},{2,4},{2,5}};
	cout<<max_overlap(input);
}