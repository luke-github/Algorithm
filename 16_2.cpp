#include <iostream>
#include <vector>
using namespace std;

bool is_match_handler(string& r, int r_index, string& s, int s_index){
	if(r_index == r.size()){
		return true;
	}
	if(r_index == r.size()-1 && r[r_index] == '$'){
		return s_index == s.size();
	}
	if(r.size() - r_index >=2 && r[r_index+1]=='*'){
		if(is_match_handler(r,r_index+2,s,s_index)){
			return true;
		}
		while(s_index < s.size() && (r[r_index]=='.' || r[r_index]==s[s_index])) {
			if(is_match_handler(r,r_index+2,s,++s_index)){
				return true;
			}
		}
	}
	return s_index<s.size() && (r[r_index]=='.' || r[r_index]==s[s_index]) && is_match_handler(r,r_index+1,s,s_index+1);
}

bool is_match( string& r,  string& s){
	if(r.front()=='^'){
		return is_match_handler(r,1,s,0);
	}else{
		for(int i=0;i<s.size();i++){
			if(is_match_handler(r,0,s,i)){
				return true;
			}
		}
	}
	return false;
}

int main(){
	string s = "abcde";
	string r= "^abc.m";
	cout<<is_match(r,s);
}

