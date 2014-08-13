#include <vector>
#include <iostream>
#include <queue>
using namespace std;

struct TrafficElement{
	bool operator < (const TrafficElement& that) const {
		return volume < that.volume;
	}
	bool operator == (const TrafficElement& that) const {
		return volume == that.volume;
	}
	int time, volume;
};

void cal_max_window_traffic(vector<TrafficElement>& vec){
	queue<TrafficElement> q;
	for(int i=0;i<vec.size();i++){
		q.emplace(vec[i]);
		while(vec[i].time - q.front().time > w){
			q.dequeue();
		}
		cout<<q.max().volume<<endl;
	}
}