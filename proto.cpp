#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

string shortest_filepath(const string& path){
	vector<string> stk;
	stringstream ss(path);
	string token;
	if(path.front()=='/'){
		stk.push_back("/");
	}
	while(getline(ss,token,'/')){
		if(token==".."){
			if(stk.empty()||stk.back()==".."){
				stk.push_back("..");
			}else{
				if(stk.back()=="/"){
					throw invalid_argument("invalid_input");
				}
				stk.pop_back();
			}
		}else if(token!=""&&token!="."){
			for(const char c : token){
				if(!isalnum(c)){
					throw invalid_argument("this is not a valid input");
				}
			}
			stk.push_back(token);
		}
	}
	string result;
	result = stk[0];
	for(int i=1;i<stk.size();i++){
		if(stk[i-1]!="/")
			result += "/";
		result += stk[i];
	}
	return result;
}

int main(){
	string input = "/a1/b2/c3/./../../file";
	cout<<shortest_filepath(input);
}


