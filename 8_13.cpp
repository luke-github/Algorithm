#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

void zipped_fun(shared_ptr<ListNode<int>>& b, shared_ptr<ListNode<int>>* a){
	shared_ptr<ListNode<int>> temp = (*a)->next;
	(*a)->next = b;
	(*a)=temp;
}

shared_ptr<ListNode<int>> zipped_link(shared_ptr<ListNode<int>>& head){
	shared_ptr<ListNode<int>> slow =  head, fast = head,  pre_slow = head;
	while(fast){
		fast = fast->next;
		if(fast){
			pre_slow = slow;
			slow = slow->next;
			fast = fast->next;
		}
	}
	if(!pre_slow)
		return head;
	pre_slow->next = nullptr;
	shared_ptr<ListNode<int>> reverse = reverse_link_list(slow), cur = head;
	while(cur&&reverse){
		zipped_fun(reverse,&cur);
		if(cur){
			zipped_fun(cur,&reverse);
		}
	}
	return head;
}

