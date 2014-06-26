#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct BST_Node{
	T data;
	shared_ptr<BST_Node<T>> left;
	shared_ptr<BST_Node<T>> right;
	shared_ptr<BST_Node<T>> parent;
	T size;
};

shared_ptr<BST_Node<int>> successor_inorder(shared_ptr<BST_Node<int>> node){
	if(node->right){
		node=node->right;
		while(node->left){
			node=node->left;
		}
		return node;
	}else{
		while(node->parent){
			if(node->parent->left==node){
				return node->parent;
			}
			node=node->parent;
		}
	}
	return nullptr;
}

int main(){
	
}