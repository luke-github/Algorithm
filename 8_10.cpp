#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> remove_duplicate(shared_ptr<ListNode<int>>& head){
	shared_ptr<ListNode<int>> pre=nullptr, cur=head;
	while(cur){
		if(pre&&pre->data==cur->data){
			pre->next=cur->next;
			cur=cur->next;
		}else{
		    pre=cur;
			cur=cur->next;
		}
	}
	return head;
}

int main(){

	shared_ptr<ListNode<int>> L1 = make_shared<ListNode<int>>(ListNode<int>{1,nullptr});
	shared_ptr<ListNode<int>> L2 = make_shared<ListNode<int>>(ListNode<int>{2,nullptr});
	shared_ptr<ListNode<int>> L3 = make_shared<ListNode<int>>(ListNode<int>{3,nullptr});
	shared_ptr<ListNode<int>> L4 = make_shared<ListNode<int>>(ListNode<int>{2,nullptr});
	shared_ptr<ListNode<int>> L5 = make_shared<ListNode<int>>(ListNode<int>{5,nullptr});
	L1->next=L2;
	L2->next=L3;
	L3->next=L4;
	L4->next=L5;
	shared_ptr<ListNode<int>> result =  remove_duplicate(L1);
	while(result){
		cout<<result->data<<" ";
		result=result->next;
	}


}