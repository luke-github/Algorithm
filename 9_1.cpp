#include <iostream>
#include <stack>
using namespace std;

class My_Stack{
public:
	void push(int x){
		s_.emplace(x,s_.empty()? x : max(x,s_.top().second));
	}
	int pop(){
		if(s_.empty()){
			throw length_error("the stack is empty");
		}
		int result = s_.top().first;
		s_.pop();
		return result;
	}
	int max_num(){
		if(s_.empty()){
			throw length_error("the stack is empty");
		}
		return s_.top().second;
	}
private:
	stack<pair<int,int> > s_;
};

int main(){
	My_Stack m1;
	m1.push(1);
	cout<<m1.max_num();
	m1.push(2);
	cout<<m1.max_num();
	m1.push(3);
	cout<<m1.max_num();
	m1.push(4);
	cout<<m1.max_num();
	m1.push(5);
	cout<<m1.max_num();

}