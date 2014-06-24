#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

string shortest_filepath(const string& path){
	stringstream ss(path);
	vector<string> stk;
	string token;
	if(path.front()=='/')
		stk.push_back("/");
	while(getline(ss,token,'/')){
		if(token==".."){
			if(stk.empty()||stk.back()==".."){
				stk.push_back("..");
			}
			else{
				if(stk.back()=="/"){
					throw invalid_argument("invalid input path");
				}
				stk.pop_back();
			}
		}else if(token!=""&&token!="."){
			for(char c : token){
				if(!isalnum(c)){
					throw invalid_argument("invalid input path");
				}
			}
			stk.push_back(token);
		}
	}
	string result;
	auto itor = stk.begin();
	result = *itor++;
	while(itor!=stk.end()){
		if(*(itor-1)!="/"){
			result += "/";
		}
		result += *itor++;
	}
	return result;
}

int main(){
	string input = "/a1/b2/c3/./../../file";
	cout<<shortest_filepath(input);
}