#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> reverse_link_list(shared_ptr<ListNode<int>>& head){
	shared_ptr<ListNode<int>> cur=head,pre=nullptr;
	while(cur){
		shared_ptr<ListNode<int>> temp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = temp;
	}
	return pre;
}

int main(){
	shared_ptr<ListNode<int>> L1 = make_shared<ListNode<int>>(ListNode<int>{1,nullptr});
	shared_ptr<ListNode<int>> L2 = make_shared<ListNode<int>>(ListNode<int>{2,nullptr});
	shared_ptr<ListNode<int>> L3 = make_shared<ListNode<int>>(ListNode<int>{3,nullptr});
	shared_ptr<ListNode<int>> L4 = make_shared<ListNode<int>>(ListNode<int>{4,nullptr});
	L1->next = L2;
	L2->next = L3;
	L3->next = L4;
	shared_ptr<ListNode<int>> result = reverse_link_list(L1);
	while(result){
		cout<<result->data<<":";
		result=result->next;
	}
}


