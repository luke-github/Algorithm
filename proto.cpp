#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

 int len_list(shared_ptr<ListNode<int>> l);
 void advance_n_steps(shared_ptr<ListNode<int>>& ptr,int n);


shared_ptr<ListNode<int>> find_coverage(shared_ptr<ListNode<int>>& L, shared_ptr<ListNode<int>>& R){
	int lenl=len_list(L);
	int lenr=len_list(R);
	advance_n_steps(lenl>lenr?L:R,abs(lenl - lenr));
	while(L&&R&&L!=R){
		L=L->next;
		R=R->next;
	}
	return L;
}

int len_list(shared_ptr<ListNode<int>> l){
	int counter=0;
	while(l){
		counter++;
		l=l->next;
	}
	return counter;
}

void advance_n_steps(shared_ptr<ListNode<int>>& ptr,int n){
	while(n){
		ptr=ptr->next;
		n--;
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
	L4->next=nullptr;
	L5->next=L2;
	shared_ptr<ListNode<int>> result = find_coverage(L1,L5);
	cout<<result->data;
}