#include <iostream>
#include <vector>
using namespace std;

struct interval{
	int start;
	int end;
};

struct endpoint{
	bool operator < (const endpoint& e) const{
		return time!=e.time ? time<e.time : (isStart&&!e.isStart);
	}
	int time;
	bool isStart;
};

int find_max_overlap(vector<interval>& vec){
	int max_counter=0;
	int counter=0;
	vector<endpoint> points;
	for(const interval x: vec){
		points.emplace_back(endpoint{x.start,true});
		points.emplace_back(endpoint{x.end,false});
	}
	sort(points.begin(),points.end());
	for(const endpoint x: points){
		if(x.isStart){
			max_counter=max(max_counter,++counter);
		}else{
			counter--;
		}
	}
	return max_counter;
}

int main(){
	vector<interval> input = {{1,4},{2,5},{2,3},{4,9}};
	cout<<find_max_overlap(input);
}












