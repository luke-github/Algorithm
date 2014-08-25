#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct LineSegment{
	int left, right;
	int color;
	int height;
};

class Endpoint{
public:
	bool operator < (Endpoint that) const{
		return value() < that.value();
	}
	int value() const{
		return is_left? L_->left : L_->right;
	}

	bool is_left;
	LineSegment* L_;
};

void print_coverage(const vector<LineSegment>& A){
	vector<Endpoint> E;
	for( auto x : A){
		E.emplace_back(Endpoint{true,&x});
		E.emplace_back(Endpoint{false,&x});
	}
	sort(E.begin(),E.end());

	int prev_xaixs = E.front()->value();
	shared_ptr<LineSegment> prev = nullptr;
	map<int, LineSegment*> T;
	for( auto e: E){
		if(!T.empty()&&prev_xaixs!=e.value()){
			
		}
	}
}