#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TrafficElement{
	bool operator < (const TrafficElement& that) const {
		return volume < that.volume;
	}
	bool operator == (const TrafficElement& that) const {
		return volume ==  that.volume;
	}
	int time,volume;
};

void max_traffic_func(vector<TrafficElement>& vec,int w){
	queue<TrafficElement> q;
	for(int i=0;i<vec.size();i++){
		q.emplace(vec[i]);
		while(vec[i].time - q.front().time > w){
			q.dequeue();
		}
		cout<<q.max().volume<<endl;
	}
}