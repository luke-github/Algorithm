#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

void delete_the_kth_node(shared_ptr<ListNode<int>>& head, int k){
	shared_ptr<ListNode<int>> itor = head;
	while(itor&&k--){
		itor=itor->next;
	}
	if(k){
		throw length_error("error");
	}
	shared_ptr<ListNode<int>> cur = head, pre=nullptr;
	while(itor){
		pre=cur;
		cur=cur->next;
		itor=itor->next;
	}
	pre->next=cur->next;
}

int main(){
	
}