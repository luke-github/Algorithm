#include <iostream>
#include <memory>
#include <map>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};


shared_ptr<ListNode<int>> find_coverage_(shared_ptr<ListNode<int>>& L, shared_ptr<ListNode<int>>& R){
	shared_ptr<ListNode<int>> loop1 = find_cycle(L);
	shared_ptr<ListNode<int>> loop2 = find_cycle(R);
	if(!loop1&&!loop2){
		return find_noncycle_coverage(L,R);
	}
	else if(loop1&&loop2){
		shared_ptr<ListNode<int>> temp = loop1-next;
		while(temp!=loop1 && temp!=loop2){
			temp=temp->next;
		}
		return temp==loop2? temp: nullptr;
	}
	return nullptr;
}