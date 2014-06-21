#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

void append_node(shared_ptr<ListNode<int>>& node, shared_ptr<ListNode<int>>* head, shared_ptr<ListNode<int>>* tail);
void append_node_and_advance(shared_ptr<ListNode<int>>* head,shared_ptr<ListNode<int>>* tail,shared_ptr<ListNode<int>>* node);

shared_ptr<ListNode<int>> merge_sorted_list(shared_ptr<ListNode<int>> F,shared_ptr<ListNode<int>> L){
	shared_ptr<ListNode<int>> sorted_head=nullptr, tail=nullptr;
	while(F&&L)
		append_node_and_advance(&sorted_head,&tail,((F->data)< (L->data)) ? &F : &L);
	if(F){
		append_node(F,&sorted_head,&tail);
	}
	if(L){
		append_node(L,&sorted_head,&tail);
	}
	return sorted_head;
} 

void append_node_and_advance(shared_ptr<ListNode<int>>* head,shared_ptr<ListNode<int>>* tail,shared_ptr<ListNode<int>>* node){
	append_node(*node,head,tail);
	*node = (*node)->next;
}

void append_node(shared_ptr<ListNode<int>>& node, shared_ptr<ListNode<int>>* head, shared_ptr<ListNode<int>>* tail){
	*head?(*tail)->next=node:(*head)=node;
	*tail = node;
}



int main(){
	ListNode<int> node1;
	// node1.data=1;
	// node2.data=2;
	shared_ptr<ListNode<int>> p1(&node1);
}