#include <stack>
#include <iostream>
#include <sstream>
using namespace std;

double RPN_solution(const string& s){
	stringstream ss(s);
	stack<double> res_stack;
	string symbol;
	while(getline(ss,symbol,',')){
		if(symbol=="+" || symbol=="-" ||symbol=="*" ||symbol=="/"){
			int second = res_stack.top();
			res_stack.pop();
			int first = res_stack.top();
			res_stack.pop();
			switch(symbol.front()){
				case '+':
					res_stack.emplace(first+second);
					break;
				case '-':
					res_stack.emplace(first - second);
					break;
				case '*':
					res_stack.emplace(first * second);
					break;
				case '/':
					res_stack.emplace(first / second);
					break;
			}
		}else{
			res_stack.emplace(stoi(symbol));
		}
	}
	return res_stack.top();
}

int main(){
	string input = "3,4,+,5,3,-,*";
	cout<<RPN_solution(input);
}
