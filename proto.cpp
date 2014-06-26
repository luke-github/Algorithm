#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct BST_Node{
	T data;
	shared_ptr<BST_Node<T>> left;
	shared_ptr<BST_Node<T>> right;
};

bool check_path_sum(shared_ptr<BST_Node<int>>& head, int num, int sum){
	if(!head){
		return false;
	}
	num = num + head->data;
	if(!head->left&&!head->right){
		return num==sum;
	}
	return check_path_sum(head->left,num,sum) || check_path_sum(head->right,num,sum);
}