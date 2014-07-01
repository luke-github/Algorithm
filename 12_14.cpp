#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int find(ifstream* ifs){
	vector<size_t> counter(1<<16,0);
	unsigned int x;
	while(*ifs>>x){
		++counter[x>>16];
	}
	for(int i=0;i<counter.size();i++){
		if(counter[i]<(1<<16)){
			bitset<(1<<16)> bit_vec;
			ifs->clear();
			ifs->seekg(0,ios::beg);
			while(*ifs>>x){
				if(i==(x>>16)){
					bit_vec.set(((1<<16)-1)&x);
				}
			}
			ifs->close();
			for(int j=0;j<(1<<16);j++){
				if(bit_vec.test(j)==0){
					return (i<<16)|j;
				}
			}
		}
	}
	return -1;
}