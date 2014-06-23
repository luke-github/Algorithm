#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<int>> next;
};

void add_node(shared_ptr<ListNode<int>> node, shared_ptr<ListNode<int>>& head, shared_ptr<ListNode<int>>& tail){
	if(!head){
		head=node;
		tail=node;
	}else{
		tail->next=node;
		tail=tail->next;
	}
}

shared_ptr<ListNode<int>> pivot_list(shared_ptr<ListNode<int>>& head, int x){
	shared_ptr<ListNode<int>> now = head;
	shared_ptr<ListNode<int>> less_head=nullptr, less_tail=nullptr, equal_head=nullptr,equal_tail=nullptr,larger_head=nullptr,larger_tail=nullptr;
	while(now){
		if(now->data<x){
			add_node(now,less_head,less_tail);
		}
		else if(now->data==x)
			add_node(now,equal_head,equal_tail);
		else
			add_node(now,larger_head,larger_tail);
		now=now->next;
	}
	if(less_tail)
		less_tail->next=nullptr;
	if(equal_tail)
		equal_tail->next=nullptr;
	if(larger_tail)
		larger_tail->next=nullptr;
	if(larger_head)
		equal_tail->next=larger_head;
	if(equal_head)
		less_tail->next=equal_head;
	return less_head;
}

int main(){

}