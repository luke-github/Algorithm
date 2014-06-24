#include <iostream>
#include <stack>
using namespace std;
void insert_node(int node,stack<int>* st);
void sort_stack(stack<int>* st){
	if(!st->empty()){
		int temp = st->top();
		st->pop();
		sort_stack(st);
		insert_node(temp,st);
	}
}

void insert_node(int node,stack<int>* st){
	if(st->empty()||node>=st->top()){
		st->push(node);
	}else{
		int temp = st->top();
		st->pop();
		insert_node(node,st);
		st->push(temp);
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