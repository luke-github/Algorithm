#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> reverse_sublist(shared_ptr<ListNode<int>> L, int s, int f){
	if(s==f){
		return L;
	}
	size_t count = 1;
	shared_ptr<ListNode<int>> s_ptr=L, pre_s_ptr=nullptr;
	while(count<s){
		count++;
		pre_s_ptr = s_ptr;
		s_ptr = s_ptr->next;
	}
	if(pre_s_ptr){
		pre_s_ptr->next=nullptr;
	}
	shared_ptr<ListNode<int>> cur=s_ptr,pre=nullptr,f_ptr=nullptr,next_f_ptr=nullptr;
	while(count<f){
		count++;
		f_ptr = cur->next;
		next_f_ptr = f_ptr->next;
		cur->next = pre;
		pre = cur;
		cur = f_ptr;
	}
	f_ptr->next = pre;
	s_ptr->next = next_f_ptr;
	if(pre_s_ptr){
		pre_s_ptr->next = f_ptr;
		return L;
	}else{
		return f_ptr;
	}

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
	shared_ptr<ListNode<int>> result = reverse_sublist(L1,2,5);
	while(result){
		cout<<result->data<<" ";
		result=result->next;
	}

}