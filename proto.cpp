#include <iostream>
#include <stack>
using namespace std;

int longest_match(const string& s){
	int max_len=0, last_end=0;
	stack<int> st;
	for(int i=0;i<s.size();i++){
		if(s[i]=='('){
			st.emplace(i);
		}else{
			if(st.empty()){
				last_end = i+1;
			}else{
				st.pop();
				int start = st.empty()? last_end-1: st.top();
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