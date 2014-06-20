#include <iostream>
using namespace std;
string read_and_speak_handler(string& s);
string read_and_speak(int num){
	string res = "1";
	for(int i=1;i<num;i++)
		res = read_and_speak_handler(res);
	return res;
}

string read_and_speak_handler(string& s){
	string result;
	for(int i=0;i<s.size();i++){
		int counter=1;
		while(i+1<s.size() && s[i]==s[i+1]){
			i++;
			counter++;
		}
		result += to_string(counter) + s[i];
	}
	return result;
}

int main(){
	cout<<read_and_speak(5);
}