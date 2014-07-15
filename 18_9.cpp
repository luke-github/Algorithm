#include <iostream>
#include <sstream>
using namespace std;

string majority_search_algorithm(istringstream* ifs){
	string str,res;
	int count=0;
	while(*ifs>>str){
		if(count==0){
			res =str;
			count++;
		}else if(res==str){
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
	cout<<majority_search_algorithm(&is);
}