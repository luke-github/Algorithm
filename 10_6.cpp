#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct BST_Node{
	T data;
	shared_ptr<BST_Node<T>> left;
	shared_ptr<BST_Node<T>> right;
};

int calculate_sum(shared_ptr<BST_Node<int>>& head, int num){
	if(!head){
		return 0;
	}
	num = (num<<1) + head->data;
	if(!head->left&&!head->right){
		return num;
	}
	return calculate_sum(head->left,num)+calculate_sum(head->right,num);
}

int main(){
	shared_ptr<BST_Node<int>> L1 = make_shared<BST_Node<int>>(BST_Node<int>{1,nullptr,nullptr});
	shared_ptr<BST_Node<int>> L2 = make_shared<BST_Node<int>>(BST_Node<int>{0,nullptr,nullptr});
	shared_ptr<BST_Node<int>> L3 = make_shared<BST_Node<int>>(BST_Node<int>{0,nullptr,nullptr});
	shared_ptr<BST_Node<int>> L4 = make_shared<BST_Node<int>>(BST_Node<int>{1,nullptr,nullptr});
	shared_ptr<BST_Node<int>> L5 = make_shared<BST_Node<int>>(BST_Node<int>{0,nullptr,nullptr});
	shared_ptr<BST_Node<int>> L6 = make_shared<BST_Node<int>>(BST_Node<int>{1,nullptr,nullptr});
	L1->left=L2;
	L1->right=L3;
	L2->left=L4;
	L2->right=L5;
	L3->left=L6;
	cout<<calculate_sum(L1,0);
}