#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

void advance_node(shared_ptr<ListNode<int>>* n){
	cout<<(*n)->data<<endl;
	(*n)=(*n)->next;
	(*n)=(*n)->next;

}

void operation(shared_ptr<ListNode<int>>& head){
	advance_node(&head);
	cout<<head->data<<endl;
}

int main(){
	shared_ptr<ListNode<int>> T1 = make_shared<ListNode<int>>(ListNode<int>{1,nullptr});
	shared_ptr<ListNode<int>> T2 = make_shared<ListNode<int>>(ListNode<int>{2,nullptr});
	shared_ptr<ListNode<int>> T3 = make_shared<ListNode<int>>(ListNode<int>{3,nullptr});
	shared_ptr<ListNode<int>> T4 = make_shared<ListNode<int>>(ListNode<int>{4,nullptr});
	T1->next = T2;
	T2->next = T3;
	T3->next = T4;
	operation(T1);
}