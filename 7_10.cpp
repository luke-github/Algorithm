#include <iostream>
#include <sstream>
using namespace std;

string decode(const string& s){
	string result;
	int count=0;
	for(char c : s){
		if(isdigit(c)){
			count = count*10+c-'0';
		}else{
			result.append(count,c);
			count=0;
		}
	}
	return result;
}

string encode(const string& s){
	stringstream ss;
	int count =1;
	for(int i=1;i<s.size();i++){
		if(s[i]==s[i-1]){
			count++;
		}else{
			ss<<count<<s[i-1];
			count=1;
		}
	}
	ss<<count<<s.back();
	return ss.str();
}

int main(){
	string input = "aaabbcccc";
	cout<<encode(input)<<endl;
	cout<<decode(encode(input));
}