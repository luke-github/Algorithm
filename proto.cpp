#include <iostream>
#include <sstream>
using namespace std;

string decode(const string& s){
	int count=0;
	string result;
	for(char c : s){
		if(isdigit(c)){
			count=count*10+c-'0';
		}else{
			result.append(count,c);
			count=0;
		}
	}
	return result;
}

string encode(const string& s){
	int count=1;
	stringstream result;
	for(int i=1;i<s.size();i++){
		if(s[i]==s[i-1]){
			count++;
		}else{
			result<<count<<s[i-1];
			count=1;
		}
	}
	result<<count<<s.back();
	return result.str();
}

int main(){
	string input = "aaabbbbbcc";
	cout<<encode(input)<<endl;
	cout<<decode(encode(input));
}