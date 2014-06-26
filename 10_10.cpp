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

shared_ptr<BST_Node<int>> successor_node(shared_ptr<BST_Node<int>>& node){
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
	shared_ptr<BST_Node<int>> L1 = make_shared<BST_Node<int>>(BST_Node<int>{1,nullptr,nullptr,nullptr,0});
	shared_ptr<BST_Node<int>> L2 = make_shared<BST_Node<int>>(BST_Node<int>{2,nullptr,nullptr,nullptr,0});
	shared_ptr<BST_Node<int>> L3 = make_shared<BST_Node<int>>(BST_Node<int>{3,nullptr,nullptr,nullptr,0});
	shared_ptr<BST_Node<int>> L4 = make_shared<BST_Node<int>>(BST_Node<int>{4,nullptr,nullptr,nullptr,0});
	shared_ptr<BST_Node<int>> L5 = make_shared<BST_Node<int>>(BST_Node<int>{5,nullptr,nullptr,nullptr,0});
	L1->left=L2;
	L1->right=L3;
	L2->left=L4;
	L2->right=L5;
	L2->parent=L1;
	L3->parent=L1;
	L4->parent=L2;
	L5->parent=L2;
	shared_ptr<BST_Node<int>> result = successor_node(L4);
	cout<<result->data;
}


//    L1
//   /  \
//  L2  L3
//  / \
// L4 L5