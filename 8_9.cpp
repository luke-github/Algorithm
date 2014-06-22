#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

void delete_last_kth_node(shared_ptr<ListNode<int>>& head, int k){
	shared_ptr<ListNode<int>> itor = head;
	while(k&&itor){
		k--;
		itor=itor->next;
	}
	if(k){
		throw length_error("The length of list is error");
	}
	shared_ptr<ListNode<int>> cur=head, pre=nullptr;
	while(itor){
		pre=cur;
		cur=cur->next;
		itor=itor->next;
	}
	pre->next=cur->next;
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
	delete_last_kth_node(L1,4);
	while(L1){
		cout<<L1->data<<" ";
		L1=L1->next;
	}
}