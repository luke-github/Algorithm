#include <iostream>
#include <stack>
using namespace std;

void insert_element(int element, stack<int>* st){
	if(st->empty()||element>=st->top()){
		st->push(element);
	}else{
		int temp = st->top();
		st->pop();
		insert_element(element,st);
		st->push(temp);
	}
}

void sort_stack(stack<int>* st){
	if(!st->empty()){
		int temp = st->top();
		st->pop();
		sort_stack(st);
		insert_element(temp,st);
	}
}

int main(){
	stack<int> my_stack;
	my_stack.push(1);
	my_stack.push(4);
	my_stack.push(2);
	my_stack.push(7);
	my_stack.push(5);
	sort_stack(&my_stack);
	while(!my_stack.empty()){
		cout<<my_stack.top()<<" ";
		my_stack.pop();
	}
}
