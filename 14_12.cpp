#include <iostream>
#include <memory>
#include <vector>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> merge_two_list(shared_ptr<ListNode<int>> l1,shared_ptr<ListNode<int>> l2);

shared_ptr<ListNode<int>> merge_sort_list(shared_ptr<ListNode<int>> head){
	if(head==nullptr || head->next==nullptr){
		return head;
	}
	shared_ptr<ListNode<int>> fast=head, slow=head, slow_pre=nullptr;
	while(fast){
		fast=fast->next;
		if(fast){
			fast=fast->next;
			slow_pre=slow;
			slow=slow->next;
		}
	}
	slow_pre=nullptr;
	fast=merge_sort_list(head);
	slow=merge_sort_list(slow);
	return merge_two_list(fast,slow);
}
