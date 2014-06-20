#include <iostream>
#include <vector>
using namespace std;

string sin_string(const string& s){
	string result;
	int index = 1;
	while(index<s.size()){
		result += s[index];
		index += 2;
	}
}