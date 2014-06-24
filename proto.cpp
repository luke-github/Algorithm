#include <iostream>
#include <stack>
#include <memory>
using namespace std;

template<class T>
struct BST_Node{
	T data;
	shared_ptr<BST_Node<int>> left;
	shared_ptr<BST_Node<int>> right;
};

void print_BST_nodes(shared_ptr<BST_Node<int>>& node){
	stack<shared_ptr<BST_Node<int>>> stk;
	while(!stk.empty()||node){
		if(node){
			stk.push(node);
			node=node->left;
		}else{
			node=stk.top();
			stk.pop();
			cout<<node->data;
			node=node->right;
		}
	}
}

int main(){
	shared_ptr<BST_Node<int>> L1 = make_shared<BST_Node<int>>(BST_Node<int>{1,nullptr});
	shared_ptr<BST_Node<int>> L2 = make_shared<BST_Node<int>>(BST_Node<int>{2,nullptr});
	shared_ptr<BST_Node<int>> L3 = make_shared<BST_Node<int>>(BST_Node<int>{3,nullptr});
	shared_ptr<BST_Node<int>> L4 = make_shared<BST_Node<int>>(BST_Node<int>{4,nullptr});
	shared_ptr<BST_Node<int>> L5 = make_shared<BST_Node<int>>(BST_Node<int>{5,nullptr});
	L1->left=L2;
	L1->right=L3;
	L2->left=L4;
	L3->right=L5;
	print_BST_nodes(L1);
}