#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
};

int max_depth(shared_ptr<BST<int>>& head){
	if(!head){
		return 0;
	}
	return 1+max(max_depth(head->left),max_depth(head->right));
}

int min_depth(shared_ptr<BST<int>>& head){
	if(!head){
		return 0;
	}else{
		return 1+min(min_depth(head->left),min_depth(head->right))
	}
}