#include <iostream>
using namespace std;

string sin_string(const string& s){
	int index=1;
	string result;
	while(index<s.size()){
		result += s[index];
		index += 4;
	}
	index = 0;
	while(index<s.size()){
		result += s[index];
		index += 2;
	}
	index = 3;
	while(index<s.size()){
		result+=s[index];
		index +=4;
	}
	return result;
}

int main(){
	cout<<sin_string("1234567890");
}