#include <iostream>
#include <sstream>
using namespace std;

string majority_algorithm(istringstream* in){
	string buf,res;
	int count = 0;
	while(*in>>buf){
		if(count==0){
			res = buf;
			count++;
		}else if(res==buf){
			count++;
		}else{
			count--;
		}
	}
	return res;
}


int main(){
	string str = "a b a a b c a a a";
	istringstream is(str);
	cout<<majority_algorithm(&is);
}