#include <iostream>
#include <memory>
#include <map>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};
int len_list(shared_ptr<ListNode<int>>& l);
void next_k(shared_ptr<ListNode<int>>* ptr, int k);
shared_ptr<ListNode<int>> find_coverage(shared_ptr<ListNode<int>>& L, shared_ptr<ListNode<int>>& R){
	int lenL=len_list(L);
	int lenR=len_list(R);
	next_k((lenL > lenR)?&L:&R,abs(lenL-lenR));
	while(L && R && L!=R){
		L=L->next;
		R=R->next;
	}
	return L;

}

int len_list(shared_ptr<ListNode<int>>& l){
	int counter=0;
	while(l){
		counter++;
		l=l->next;
	}
	return counter;
}

void next_k(shared_ptr<ListNode<int>>* ptr, int k){
	// shared_ptr<ListNode<int>> cur = ptr;
	while(k){
		*ptr=(*ptr)->next;
		k--;
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
	// L4->next=nullptr;
	L5->next=L3;
	shared_ptr<ListNode<int>> result = find_coverage(L1,L5);
	// cout<<result->data;
}