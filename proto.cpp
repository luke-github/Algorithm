#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int find_missing_address(ifstream* ifs){
	vector<size_t> counter(1<<16,0);
	unsigned int x;
	while(*ifs>>x){
		++counter[x>>16];
	}
	for(int i=0;i<counter.size();i++){
		if(counter[i]<(1<<16)){
			ifs->clear();
			ifs->seekg(0,ios::beg);
			bitset<(1<<16)> bit_set;
			while(*ifs>>x){
				if((x>>16)==i){
					bit_set.set(((1<<16)-1)&x);
				}
			}
			ifs->close();
			for(int j=0;j<(1<<16);j++){
				if(bit_set.test(j)==0)
					return i<<16|j;
			}
		}
	}
	return -1;
}