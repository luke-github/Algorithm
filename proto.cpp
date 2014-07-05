#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> merge_list(shared_ptr<ListNode<int>> l1,shared_ptr<ListNode<int>> l2);

shared_ptr<ListNode<int>> merge_sort_list(shared_ptr<ListNode<int>> head){
	if(head==nullptr || head->next==nullptr){
		return head;
	}
	shared_ptr<ListNode<int>> fast=head,slow=head,pre_slow=nullptr;
	while(fast){
		fast=fast->next;
		if(fast){
			pre_slow=slow;
			fast=fast->next;
			slow=slow->next;
		}
	}
	pre_slow=nullptr;
	fast=merge_sort_list(head);
	slow=merge_sort_list(slow);
	return merge_list(fast,slow);
}