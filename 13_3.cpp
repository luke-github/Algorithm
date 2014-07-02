#include <iostream>
#include <unordered_map>
using namespace std;

bool anoymous_letter(const string& L, const string& M){
	unordered_map<char,int> hash;
	for_each(L.begin(),L.end(),[&hash](const char& c){++hash[c];});
	for(const char& x : M){
		auto p = hash.find(x);
		if(p!=hash.cend()){
			if(--hash[x]==0){
				hash.erase(p);
				if(hash.empty()){
					return true;
				}
			}
		}
	}
	return false;
}

int main(){
	string input1= "aabbcc";
	string input2 = "aaabbbcdc";
	cout<<anoymous_letter(input1,input2);
}