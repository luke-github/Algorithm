#include <iostream>
#include <unordered_map>
using namespace std;

int roman_to_int(const string& input){
	unordered_map<char,int> M = {{'I',1},
								{'V',5},
								{'X',10},
								{'L',50},
								{'C',100},
								{'D',500},
								{'M',1000},};
	int result = M[input.back()];
	for(int i=input.size()-2;i>=0;i--){
		if(M[input[i]]<M[input[i+1]])
			result-=M[input[i]];
		else
			result+=M[input[i]];
	}
	return result;
}

int main(){
	string in = "LIII";
	cout<<roman_to_int(in);
}