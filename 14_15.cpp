#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void indirect_sort(const string& filename){
	ifstream ifs(filename.c_str());
	vector<int> vec;
	int x;
	while(ifs>>x){
		vec.emplace_back(x);
	}
	vector<int*> point_vec;
	for(int &m: vec){
		point_vec.emplace_back(&m);
	}
	sort(point_vec.begin(),point_vec.end(),[](const int* a,const int* b)->bool{ return *a<*b; });
	ofstream ofs("output14_15");
	for(const int* m: point_vec){
		ofs<<*m<<endl;
		cout<<*m<<" ";
	}
}

int main(){
	indirect_sort("input14_15");
} 