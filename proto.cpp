#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<int>> next;
};

bool handle_carry(shared_ptr<ListNode<int>>& head){
	if(head->data<10)
		return false;
	head->data %= 10;
	if(!head->next){
		head->next = make_shared<ListNode<int>>(ListNode<int>{0,nullptr});
	}
	head->next->data++;
	return true;
}

shared_ptr<ListNode<int>> add_two_list(shared_ptr<ListNode<int>>& l1,shared_ptr<ListNode<int>>& l2){
	shared_ptr<ListNode<int>> result = l1;
	while(l2){
		l1->data+=l2->data;
		handle_carry(l1);
		if(!l1->next){
			l1->next=l2->next;
			return result;
		}
		l1=l1->next;
		l2=l2->next;
	}
	while(l1&&handle_carry(l1)){
		l1=l1->next;
	}
	return result;
}

int main(){
	shared_ptr<ListNode<int>> L1 = make_shared<ListNode<int>>(ListNode<int>{1,nullptr});
	shared_ptr<ListNode<int>> L2 = make_shared<ListNode<int>>(ListNode<int>{0,nullptr});
	shared_ptr<ListNode<int>> L3 = make_shared<ListNode<int>>(ListNode<int>{9,nullptr});
	shared_ptr<ListNode<int>> L4 = make_shared<ListNode<int>>(ListNode<int>{9,nullptr});
	shared_ptr<ListNode<int>> L5 = make_shared<ListNode<int>>(ListNode<int>{9,nullptr});
	L1->next=L2;
	// L2->next=L3;
	L3->next=L4;
	L4->next=L5;
	shared_ptr<ListNode<int>> result = add_two_list(L1,L3);
	while(result){
		cout<<result->data<<" ";
		result=result->next;
	}
}