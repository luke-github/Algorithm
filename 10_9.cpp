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


void iteration_inorder(shared_ptr<BST_Node<int>>& head){
	shared_ptr<BST_Node<int>> cur=head, pre=nullptr, next=nullptr;
	while(cur){
		if(!pre||pre->left==cur||pre->right==cur){
			if(cur->left){
				next = cur->left;
			}else{
				cout<<cur->data<<" ";
				next = cur->right? cur->right : cur->parent;
			}
		}else if(cur->left==pre){
			cout<<cur->data<<" ";
			next = cur->right? cur->right : cur->parent;
		}else{
			next = cur->parent;
		}
		pre=cur;
		cur=next;
	}
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
	iteration_inorder(L1);
}

//    L1
//   /  \
//  L2  L3
//  / \
// L4 L5


