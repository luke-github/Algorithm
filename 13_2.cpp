#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool check_parlindrom(const string& s){
	unordered_map<char,int> hash;
	for_each(s.begin(),s.end(),[&hash](const char& c){hash[c]++;});
	int odd_counter=0;
	for(const pair<char,int>& x : hash){
		if(x.second&1 && ++odd_counter>1)
			break;
	}
	return odd_counter<=1;
}

int main(){
	string input = "abbcc";
	cout<<check_parlindrom(input);
}