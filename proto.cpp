#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<int>> next;
};

shared_ptr<ListNode<int>> reverse_list(shared_ptr<ListNode<int>>& head){
	shared_ptr<ListNode<int>> cur=head, pre=nullptr;
	while(cur){
		shared_ptr<ListNode<int>> temp = cur->next;
		cur->next=pre;
		pre=cur;
		cur=temp;
	}
	return pre;
}

bool check_list_parlindrome(shared_ptr<ListNode<int>>& head){
	shared_ptr<ListNode<int>> slow = head, fast = head;
	while(fast){
		fast=fast->next;
		if(fast){
			fast=fast->next;
			slow=slow->next;
		}
	}
	shared_ptr<ListNode<int>> result = reverse_list(slow);
	while(result && result){
		if(result->data!=head->data){
			return false;
		}
		result=result->next;
		head=head->next;
	}
	return true;
}