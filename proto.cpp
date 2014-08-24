#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
};

void Reconstruct_Tree_Handler(shared_ptr<BST<int>>& root, shared_ptr<BST<int>>* p1, shared_ptr<BST<int>>* p2, shared_ptr<BST<int>>* pre){
	if(!root){
		return;
	}
	Reconstruct_Tree_Handler(root->left,p1,p2,pre);
	if((*pre) && (*pre)->data > root->data){
		*p2 = root;
		if(!p1){
			*p1 = *pre;
		}
	}
	*pre = root;
	Reconstruct_Tree_Handler(root->right,p1,p2,pre);
}

void Reconstruct_Tree(shared_ptr<BST<int>>& head){
	shared_ptr<BST<int>> p1 = nullptr, p2 = nullptr, pre = nullptr;
	Reconstruct_Tree_Handler(head,&p1,&p2,&pre);
	if(p1&&p2){
		swap(p1->data,p2->data);
	}
}