#include <istream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

void zipped_func(shared_ptr<ListNode<int>>& b, shared_ptr<ListNode<int>>* a){
	shared_ptr<ListNode<int>> temp = (*a)->next;
	(*a)->next = b;
	(*a)=temp;
}

shared_ptr<ListNode<int>> zipped_link(shared_ptr<ListNode<int>>& head){
	shared_ptr<ListNode<int>> slow = head, fast = head, pre_slow = head;
	while(fast){
		fast = fast->next;
		if(fast){
			pre_slow= slow;
			slow = slow->next;
			fast = fast->next;
		}
	}
	pre_slow->next = nullptr;
	shared_ptr<ListNode<int>> reverse = reverse_link_list(slow), cur = head;
	while(reverse&&cur){
		zipped_func(reverse,&cur);
		if(cur){
			zipped_func(cur,&reverse);
		}
	}
}