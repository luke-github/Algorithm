#include <iostream>
#include <memory>
#include <unordered_set>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> left;
	shared_ptr<ListNode<T>> right;
	shared_ptr<ListNode<T>> parent;
};

shared_ptr<ListNode<int>> LCA(shared_ptr<ListNode<int>>& a,shared_ptr<ListNode<int>>& b){
	unordered_set<shared_ptr<ListNode<int>>> hash;
	while(a||b){
		if(a){
			if(hash.emplace(a).second==false){
				return a;
			}
			a=a->parent;
		}
		if(b){
			if(hash.emplace(b).second==false){
				return b;
			}
			b=b->parent;
		}
	}
	throw invalid_argument("no solution found");
}

int main(){
	shared_ptr<ListNode<int>> L1 = make_shared<ListNode<int>>(ListNode<int>{1,nullptr,nullptr,nullptr});
	shared_ptr<ListNode<int>> L2 = make_shared<ListNode<int>>(ListNode<int>{2,nullptr,nullptr,nullptr});
	shared_ptr<ListNode<int>> L3 = make_shared<ListNode<int>>(ListNode<int>{3,nullptr,nullptr,nullptr});
	shared_ptr<ListNode<int>> L4 = make_shared<ListNode<int>>(ListNode<int>{4,nullptr,nullptr,nullptr});
	shared_ptr<ListNode<int>> L5 = make_shared<ListNode<int>>(ListNode<int>{5,nullptr,nullptr,nullptr});
	L1->left=L2;
	L1->right=L3;
	L2->left=L4;
	L2->right=L5;
	L2->parent=L1;
	L3->parent=L3;
	L4->parent=L2;
	L5->parent=L2;
	shared_ptr<ListNode<int>> res = LCA(L4,L5);
	cout<<res->data;
}