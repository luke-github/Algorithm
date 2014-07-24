#include <iostream>
using namespace std;

string change_base(const string& s, int b1, int b2){
	bool neg = s.front()=='-';
	int x;
	for(int i = neg?1:0;i<s.size();i++){
		x *= b1;
		x += isdigit(s[i])?s[i]-'0':s[i]-'A'+10;
	}
	string res;
	while(x){
		int r = x%b2;
		res.push_back(r>=10?'A'+r-10:r+'0');
		x /= b2;
	}
	if(neg){
		res.push_back('-');
	}
	reverse(res.begin(),res.end());
	return res;
}

int main(){
	string input = "B";
	cout<<change_base(input,16,10);
}