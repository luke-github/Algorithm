#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
};

shared_ptr<BST<int>> k_node(shared_ptr<BST<int>>& head, int k){
	if(head==nullptr){
		return nullptr;
	}
	else if(head->data==k){
		shared_ptr<BST<int>> node = k_node(head->left,k);
		return node ? node : head;
	}
	return k_node(k>head->data?head->right:head->left,k);
}

shared_ptr<BST<int>> k_node_iterate(shared_ptr<BST<int>>& head, int k){
	shared_ptr<BST<int>> res = nullptr, cur = head;
	while(cur!=nullptr){
		if(cur->data<k){
			cur=cur->right;
		}else if(cur->data>k){
			cur=cur->left;
		}else{
			res = cur;
			cur = cur->left;
		}
	}
	return res;
}

int main(){
	shared_ptr<BST<int>> L1 = make_shared<BST<int>>(BST<int>{5,nullptr,nullptr});
	shared_ptr<BST<int>> L2 = make_shared<BST<int>>(BST<int>{4,nullptr,nullptr});
	shared_ptr<BST<int>> L3 = make_shared<BST<int>>(BST<int>{7,nullptr,nullptr});
	shared_ptr<BST<int>> L4 = make_shared<BST<int>>(BST<int>{3,nullptr,nullptr});
	shared_ptr<BST<int>> L5 = make_shared<BST<int>>(BST<int>{6,nullptr,nullptr});
	L1->left = L2;
	L1->right = L3;
	L2->left = L4;
	L3->left = L5;
	shared_ptr<BST<int>> res = k_node_iterate(L1,3);
	cout<<res->data;
}

//     L1
//    /  \
//   L2  L3
//  /    / 
// L4   L5