#include <iostream>
using namespace std;
string look_and_say_handler(string s);

string look_and_say(int num){
	string res = "1";
	for(int i=1;i<num;i++){
		res=look_and_say_handler(res);
	}
	return res;
}

string look_and_say_handler(string s){
	string result;
	for(int i=0;i<s.size();i++){
		int count=1;
		while((i+1)<s.size() && s[i]==s[i+1]){
			i++;
			count++;
		}
		result += to_string(count) + s[i];
	}
	return result;
}

int main(){
	cout<<look_and_say(8);
}