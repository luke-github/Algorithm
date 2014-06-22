#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> cyclic_shift(shared_ptr<ListNode<int>>& head, int k){
	shared_ptr<ListNode<int>> first=head, second=head, pre_second=nullptr;
	while(k--){
		first=first->next;
		if(!first){
			first=head;
		}
	}
	while(first->next){
		first=first->next;
		second=second->next;
	}
	pre_second=second;
	second=pre_second->next;
	pre_second->next=nullptr;
	first->next=head;
	return second;
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
	shared_ptr<ListNode<int>> result = cyclic_shift(L1,7);
	while(result){
		cout<<result->data<<" ";
		result=result->next;
	}


}