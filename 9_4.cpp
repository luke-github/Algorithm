// the logic here is very strict
#include <iostream>
#include <stack>
using namespace std;

int longest_match(const string& s){
	stack<int> left_paren;
	int max_len=0, last_end=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='('){
			left_paren.emplace(i);
		}else{
			if(left_paren.empty()){
				last_end = i+1;
			}else{
				left_paren.pop();
				int start = left_paren.empty()? last_end-1 : left_paren.top();
				max_len = max(max_len,i-start);
			}
		}
	}
	return max_len;
}
int main(){
	string input = "())()()";
	cout<<longest_match(input);
}