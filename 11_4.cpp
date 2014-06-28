#include <iostream>
#include <queue>
#include <sstream>
#include <complex>
#include <array>
using namespace std;

class Star{
public:	
	double distance() const{
		return sqrt(x_ * x_ + y_ * y_ + z_ * z_);
	}

	bool operator <(const Star& s) const{
		return distance() < s.distance();
	}

	int ID_;
	double x_, y_, z_;
};

vector<Star> cloest_starts(istringstream* sin, int k){
	priority_queue<Star,vector<Star>> max_heap;
	string line;
	while(getline(*sin,line)){
		stringstream ss(line);
		string buf;
		getline(ss,buf,',');
		int id = stoi(buf);
		array<double,3> data;
		for(int i=0;i<3;i++){
			getline(ss,buf,',');
			data[i]=stod(buf);
		}
		Star s{id,data[0],data[1],data[2]};
		if(max_heap.size()==k){
			if(s<max_heap.top()){
				max_heap.pop();
				max_heap.emplace(s);
			}
		}else{
			max_heap.emplace(s);
		}
	}
	vector<Star> result;
	while(!max_heap.empty()){
		result.push_back(max_heap.top());
		max_heap.pop();
	}
	return result;
}

int main(){
	string input = "1,1,1,1";
	input.append("\n");
	input.append("2,2,2,2\n3,3,3,3\n4,4,4,4\n5,5,5,5\n");
	istringstream ss(input);
	vector<Star> result = cloest_starts(&ss,2);
	for(Star x:result)
		cout<<x.ID_<<" ";
}