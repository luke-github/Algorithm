#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

int RPN_solution(const string& s){
	stringstream ss(s);
	string symbol;
	stack<int> result_stack;
	while(getline(ss,symbol,',')){
		if(symbol=="+" || symbol=="-" ||symbol=="*" ||symbol=="/"){
			int second = result_stack.top();
			result_stack.pop();
			int first =  result_stack.top();
			result_stack.pop();
			switch(symbol.front()){
				case '+':
					result_stack.emplace(first+second);
					break;
				case '-':
					result_stack.emplace(first-second);
					break;				
				case '*':
					result_stack.emplace(first*second);
					break;
				case '/':
					result_stack.emplace(first/second);
					break;
			}				
		}else{
			result_stack.emplace(stoi(symbol));
		}
	}
	return result_stack.top();
}

int main(){
	
}