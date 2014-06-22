#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

void append_node(shared_ptr<ListNode<int>>& node, shared_ptr<ListNode<int>>* head, shared_ptr<ListNode<int>>* tail);
void append_node_and_advance(shared_ptr<ListNode<int>>* head,shared_ptr<ListNode<int>>* tail,shared_ptr<ListNode<int>>* node);

shared_ptr<ListNode<int>> merge_sorted_list(shared_ptr<ListNode<int>> F,shared_ptr<ListNode<int>> L){
	shared_ptr<ListNode<int>> sorted_head=nullptr, tail=nullptr;
	while(F&&L)
		append_node_and_advance(&sorted_head,&tail,((F->data)< (L->data)) ? &F : &L);
	if(F){
		append_node(F,&sorted_head,&tail);
	}
	if(L){
		append_node(L,&sorted_head,&tail);
	}
	return sorted_head;
} 

void append_node_and_advance(shared_ptr<ListNode<int>>* head,shared_ptr<ListNode<int>>* tail,shared_ptr<ListNode<int>>* node){
	append_node(*node,head,tail);
	*node = (*node)->next;
}

void append_node(shared_ptr<ListNode<int>>& node, shared_ptr<ListNode<int>>* head, shared_ptr<ListNode<int>>* tail){
	*head?(*tail)->next=node:(*head)=node;
	*tail = node;
}



int main(){
	ListNode<int> node1;
	// node1.data=1;
	// node2.data=2;
	shared_ptr<ListNode<int>> p1(&node1);
}




// the following is for test the shared_ptr


// #include <iostream>
// #include <memory>
// using namespace std;

// template<class T>
// struct ListNode{
// 	T data;
// 	shared_ptr<ListNode<T>> next;
// };
// void append_and_continue(shared_ptr<ListNode<int>>& head,shared_ptr<ListNode<int>>& tail,shared_ptr<ListNode<int>>& node);
// void append_node(shared_ptr<ListNode<int>>& head,shared_ptr<ListNode<int>>&tail, shared_ptr<ListNode<int>>& node);

// shared_ptr<ListNode<int>> merge_list(shared_ptr<ListNode<int>> L, shared_ptr<ListNode<int>> R){
// 	shared_ptr<ListNode<int>> head=nullptr, tail=nullptr;
// 	while(L&&R){
// 		append_and_continue(head,tail,L->data < R->data ?L:R);
// 	}
// 	if(L)
// 		append_node(head,tail,L);
// 	if(R)
// 		append_node(head,tail,R);
// 	return head;
// }

// void append_and_continue(shared_ptr<ListNode<int>>& head,shared_ptr<ListNode<int>>& tail,shared_ptr<ListNode<int>>& node){
// 	append_node(head,tail,node);
// 	node=node->next;
// }

// void append_node(shared_ptr<ListNode<int>>& head,shared_ptr<ListNode<int>>&tail, shared_ptr<ListNode<int>>& node){
// 	head? tail->next=node : head=node;
// 	tail=node;
// }




// int main(){
// 	shared_ptr<ListNode<int>> L1 = make_shared<ListNode<int>>(ListNode<int>{1,nullptr});
// 	shared_ptr<ListNode<int>> L2 = make_shared<ListNode<int>>(ListNode<int>{3,nullptr});
// 	shared_ptr<ListNode<int>> L3 = make_shared<ListNode<int>>(ListNode<int>{5,nullptr});
// 	L1->next=L2;
// 	L2->next=L3;
// 	shared_ptr<ListNode<int>> L4 = make_shared<ListNode<int>>(ListNode<int>{2,nullptr});
// 	shared_ptr<ListNode<int>> L5 = make_shared<ListNode<int>>(ListNode<int>{4,nullptr});
// 	shared_ptr<ListNode<int>> L6 = make_shared<ListNode<int>>(ListNode<int>{6,nullptr});
// 	L4->next=L5;
// 	L5->next=L6;
// 	shared_ptr<ListNode<int>> result = merge_list(L1,L4);
// 	while(result){
// 		cout<<result->data<<" ";
// 		result=result->next;
// 	}
// }