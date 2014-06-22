#include <iostream>
#include <memory>
#include <map>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

map<shared_ptr<ListNode<int>>, bool> checker;

shared_ptr<ListNode<int>> find_loop(shared_ptr<ListNode<int>>& L){
	shared_ptr<ListNode<int>> cur = L;
	while(cur){
		if(checker[cur]){
			return cur;
		}
		checker[cur]=true;
		cur=cur->next;
	}
	return nullptr;
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
	L5->next=L1;
	shared_ptr<ListNode<int>> result = find_loop(L1);
	cout<<result->data;

}
