#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool anynomous_letter(const string& L,const string& M){
	unordered_map<char,int> hash;
	for_each(L.begin(),L.end(),[&hash](const char& c){++hash[c];});
	for(const char&c : M){
		auto p = hash.find(c);
		if(p!=hash.cend()){
			if(--hash[c]==0){
				hash.erase(p);
				if(hash.empty())
					return true;
			}
		}
	}
	return false;
}
int main(){
	string input1= "aabbcc";
	string input2 = "aaabbbcdc";
	cout<<anynomous_letter(input1,input2);
}
