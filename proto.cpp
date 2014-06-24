#include <iostream>
#include <stack>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	T order;
	shared_ptr<ListNode<int>> jump;
	shared_ptr<ListNode<int>> next;
};

void posting_list_order_recursion(shared_ptr<ListNode<int>>& node, int& counter){
	if(node&&node->order==-1){
		node->order=counter++;
		posting_list_order_recursion(node->jump,counter);
		posting_list_order_recursion(node->next,counter);
	}
}

void posting_list_order_iteration(shared_ptr<ListNode<int>>& node){
	int counter=0;
	stack<shared_ptr<ListNode<int>>> stk;
	stk.emplace(node);
	while(!stk.empty()){
		shared_ptr<ListNode<int>> cur = stk.top();
		stk.pop();
		if(cur&&cur->order==-1){
			cur->order=counter++;
			stk.emplace(cur->next);
			stk.emplace(cur->jump);
		}
	}
}

int main(){
	shared_ptr<ListNode<int>> L1 = make_shared<ListNode<int>>(ListNode<int>{1,-1,nullptr,nullptr});
	shared_ptr<ListNode<int>> L2 = make_shared<ListNode<int>>(ListNode<int>{2,-1,nullptr,nullptr});
	shared_ptr<ListNode<int>> L3 = make_shared<ListNode<int>>(ListNode<int>{3,-1,nullptr,nullptr});
	shared_ptr<ListNode<int>> L4 = make_shared<ListNode<int>>(ListNode<int>{4,-1,nullptr,nullptr});
	shared_ptr<ListNode<int>> L5 = make_shared<ListNode<int>>(ListNode<int>{5,-1,nullptr,nullptr});
	L1->next=L2;
	L2->next=L3;
	L3->next=L4;
	L4->next=L5;
	L1->jump=L3;
	L3->jump=L5;
	L2->jump=L4;
	L4->jump=L5;
	L5->jump=L1;
	int x=0;
	// posting_list_order_recursion(L1,x);
	posting_list_order_iteration(L1);
	while(L1){
		cout<<L1->order<<" ";
		L1=L1->next;
	}
}