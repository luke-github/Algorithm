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
		tail=head;
	}else{
		tail->next=node;
		tail=tail->next;
	}
}

shared_ptr<ListNode<int>> pivot_list(shared_ptr<ListNode<int>>& head,int x){
	shared_ptr<ListNode<int>> now=head,less_head=nullptr,less_tail=nullptr,equal_head=nullptr,equal_tail=nullptr,larger_head=nullptr,
	larger_tail=nullptr;
	while(now){
		if(now->data<x){
			add_node(now,less_head,less_tail);
		}
		else if(now->data == x){
			add_node(now,equal_head,equal_tail);
		}
		else
			add_node(now,larger_head,larger_tail);
		now=now->next;
	} 
	if(less_tail){
		less_tail->next=nullptr;
	}
	if(equal_tail){
		equal_tail->next=nullptr;
	}
	if(larger_tail){
		larger_tail->next=nullptr;
	}
	if(larger_head)
		equal_tail->next=larger_head;
	if(equal_head)
		less_tail->next=equal_head;
	return less_head;
}

int main(){
	shared_ptr<ListNode<int>> L1 = make_shared<ListNode<int>>(ListNode<int>{5,nullptr});
	shared_ptr<ListNode<int>> L2 = make_shared<ListNode<int>>(ListNode<int>{1,nullptr});
	shared_ptr<ListNode<int>> L3 = make_shared<ListNode<int>>(ListNode<int>{3,nullptr});
	shared_ptr<ListNode<int>> L4 = make_shared<ListNode<int>>(ListNode<int>{2,nullptr});
	shared_ptr<ListNode<int>> L5 = make_shared<ListNode<int>>(ListNode<int>{4,nullptr});
	L1->next=L2;
	L2->next=L3;
	L3->next=L4;
	L4->next=L5;
	shared_ptr<ListNode<int>> result = pivot_list(L1,3);
	while(result){
		cout<<result->data<<" ";
		result=result->next;
	}
}