#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void indirect_sort(const string& filename){
	ifstream ifs(filename);
	int x;
	vector<int> vec;
	while(ifs>>x){
		vec.emplace_back(x);
	}
	vector<int*> point_vec;
	for(int &x : vec){
		point_vec.emplace_back(&x);
	}
	sort(point_vec.begin(),point_vec.end(),[](const int* a,const int* b)->bool{return *a<*b;});
	ofstream ofs("output14_15");
	for(const int* m : point_vec){
		ofs<<*m<<endl;
	}
}

int main(){
	indirect_sort("input14_15");
}