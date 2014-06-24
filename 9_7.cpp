#include <iostream>
#include <memory>
#include <stack>
using namespace std;

template<class T>
struct ListNode{
	T data;
	T order;
	shared_ptr<ListNode<T>> jump;
	shared_ptr<ListNode<T>> next;
};

void Posting_List_Search_Recursion(shared_ptr<ListNode<int>>& node, int counter){
	if(node&&node->order==-1){
		node->order=counter++;
		Posting_List_Search_Recursion(node->jump,counter);
		Posting_List_Search_Recursion(node->next,counter);
	}
}

void Posting_List_Search_Iteration(shared_ptr<ListNode<int>>& node){
	int counter = 0;
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
	shared_ptr<ListNode<int>> L2 = make_shared<ListNode<int>>(ListNode<int>{1,-1,nullptr,nullptr});
	shared_ptr<ListNode<int>> L3 = make_shared<ListNode<int>>(ListNode<int>{1,-1,nullptr,nullptr});
	shared_ptr<ListNode<int>> L4 = make_shared<ListNode<int>>(ListNode<int>{1,-1,nullptr,nullptr});
	shared_ptr<ListNode<int>> L5 = make_shared<ListNode<int>>(ListNode<int>{1,-1,nullptr,nullptr});
	L1->next=L2;
	L2->next=L3;
	L3->next=L4;
	L4->next=L5;
	L1->jump=L3;
	L3->jump=L5;
	L2->jump=L4;
	L4->jump=L5;
	L5->jump=L1;
	Posting_List_Search_Recursion(L1,0);
	// Posting_List_Search_Iteration(L1);
	while(L1){
		cout<<L1->order<<" ";
		L1=L1->next;
	}
}