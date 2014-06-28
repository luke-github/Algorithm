#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <array>
#include <complex>
using namespace std;

class Star{
public:
	double distance() const{
		return sqrt(x_*x_+y_*y_+z_*z_);
	}
	bool operator < (const Star& s) const{
		return distance() < s.distance();
	}
	int id_;
	double x_,y_,z_;
};

vector<Star> cloest_set(istringstream* sin, int k){
	priority_queue<Star,vector<Star>> max_queue;
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
		if(k==max_queue.size()){
			if(s<max_queue.top()){
				max_queue.pop();
				max_queue.emplace(s);
			}
		}else{
			max_queue.emplace(s);
		}
	}
	vector<Star> result;
	while(!max_queue.empty()){
		result.emplace_back(max_queue.top());
		max_queue.pop();
	}
	return result;
}

int main(){
	string input = "1,1,1,1";
	input.append("\n2,2,2,2\n3,3,3,3\n4,4,4,4\n5,5,5,5\n");
	istringstream ss(input);
	vector<Star> result = cloest_set(&ss,3);
	for(Star x:result)
		cout<<x.id_<<" "<<x.distance()<<endl;
}