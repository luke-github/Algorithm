#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> even_odd_order(shared_ptr<ListNode<int>>& head){
	if(!head->next){
		return nullptr;
	}
	shared_ptr<ListNode<int>> even_cur=head, pre_even_cur=nullptr, odd_cur=head->next,odd_first=head;
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
	if(pre_even_cur)
		pre_even_cur->next=odd_first;
	return head;
}

int main(){

}