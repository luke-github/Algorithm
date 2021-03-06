#include <iostream>
#include <memory>
#include <list>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
};

shared_ptr<BST<int>> larger_than(shared_ptr<BST<int>>& head, int k){
	if(head==nullptr){
		return nullptr;
	}
	else if(head->data>=k){
		shared_ptr<BST<int>> node = larger_than(head->left,k);
		return node?node:head;
	}else{
		return larger_than(head->right,k);
	}
}


list<shared_ptr<BST<int>>> range_nodes(shared_ptr<BST<int>>& head, int low, int high){
	list<shared_ptr<BST<int>>> res;
	for(auto it = larger_than(head,low);it&&it->data<=high;it=find_successor(it)){
		res.emplace_back(it);
	}
	return res;
}