#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<int>> next;
};

shared_ptr<ListNode<int>> sort_list(const shared_ptr<ListNode<int>>& L){
	shared_ptr<ListNode<int>> head = nullptr, now = L, next = nullptr;
	while(now){
		next = now->next;
		now->next = nullptr;
		if(head){
			shared_ptr<ListNode<int>> head_ptr = head, pre_head_ptr = nullptr;
			while(head_ptr&&now->data>=head_ptr->data){
				pre_head_ptr=head_ptr;
				head_ptr=head_ptr->next;
			}
			now->next=head_ptr;
			if(pre_head_ptr){
				pre_head_ptr->next=now;
			}else{
				head=now;
			}
		}else{
			head = now;
		}
		now = next;
	}
	return head;
}

int main(){
	shared_ptr<ListNode<int>> L1 = make_shared<ListNode<int>>(ListNode<int>{5,nullptr});
	shared_ptr<ListNode<int>> L2 = make_shared<ListNode<int>>(ListNode<int>{1,nullptr});
	shared_ptr<ListNode<int>> L3 = make_shared<ListNode<int>>(ListNode<int>{3,nullptr});
	shared_ptr<ListNode<int>> L4 = make_shared<ListNode<int>>(ListNode<int>{2,nullptr});
	shared_ptr<ListNode<int>> L5 = make_shared<ListNode<int>>(ListNode<int>{4,nullptr});
	L1->next=L2;
	L2->next=L3;
	L3->next=L4;
	L4->next=L5;
	shared_ptr<ListNode<int>> result = sort_list(L1);
	while(result){
		cout<<result->data<<" ";
		result=result->next;
	}
}