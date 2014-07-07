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
		return node? node : head;
	}
	return k_node(head->data>k?head->right:head->left,k);
}

shared_ptr<BST<int>> k_node_iterate(shared_ptr<BST<int>>& head, int k){
	shared_ptr<BST<int>> res =  nullptr, cur = head;
	while(cur){
		if(cur->data<k){
			cur=cur->right;
		}else if(cur->data > k){
			cur=cur->left;
		}else{
			res = cur;
			cur=cur->left;
		}
	}
	return res;
}