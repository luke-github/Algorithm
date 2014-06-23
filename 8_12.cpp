#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<int>> next;
};

shared_ptr<ListNode<int>> even_odd_order(shared_ptr<ListNode<int>>& head){
	if(!head->next)
		return nullptr;
	shared_ptr<ListNode<int>> even_cur=head, odd_cur=head->next, pre_even_cur=nullptr, odd_first=odd_cur;
	while(even_cur&&odd_cur){
		even_cur->next=odd_cur->next;
		pre_even_cur=even_cur;
		even_cur=even_cur->next;
		if(even_cur){
			odd_cur->next=even_cur->next;
			odd_cur=odd_cur->next;
		}
	}
	if(even_cur){
		pre_even_cur=even_cur;
	}
	if(pre_even_cur){
		pre_even_cur->next=odd_first;
	}
	return head;
}

int main(){
	shared_ptr<ListNode<int>> L1 = make_shared<ListNode<int>>(ListNode<int>{1,nullptr});
	shared_ptr<ListNode<int>> L2 = make_shared<ListNode<int>>(ListNode<int>{2,nullptr});
	shared_ptr<ListNode<int>> L3 = make_shared<ListNode<int>>(ListNode<int>{3,nullptr});
	shared_ptr<ListNode<int>> L4 = make_shared<ListNode<int>>(ListNode<int>{4,nullptr});
	shared_ptr<ListNode<int>> L5 = make_shared<ListNode<int>>(ListNode<int>{5,nullptr});
	L1->next=L2;
	L2->next=L3;
	L3->next=L4;
	L4->next=L5;
	shared_ptr<ListNode<int>> result = even_odd_order(L1);
	while(result){
		cout<<result->data;
		result=result->next; 
	}
}