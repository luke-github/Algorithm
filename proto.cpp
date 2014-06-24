#include <iostream>
#include <stack>
using namespace std;


bool check_parenthese(const string& s){
	stack<char> stk;
	for(int i=0;i<s.size();i++){
		if(s[i]=='('||s[i]=='['||s[i]=='{'){
			stk.emplace(s[i]);
		}else{
			if(stk.empty())
				return false;
			if((s[i]==')'&&stk.top()!='(') || 
				(s[i]==']'&&stk.top()!='[') || 
			(s[i]=='}'&&stk.top()!='{'))
				return false;
			stk.pop();
		}
	}
	return stk.empty();
}

int main(){
	string input = "()[]{}{[()()]}";
	cout<<check_parenthese(input);
}