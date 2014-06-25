#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
};
bool check_symmetric_tree_handler(shared_ptr<BST<int>>& leftnode, shared_ptr<BST<int>>& rightnode);
bool check_symmetric_tree(shared_ptr<BST<int>>& head){
	return !head || check_symmetric_tree_handler(head->left,head->right);
}
bool check_symmetric_tree_handler(shared_ptr<BST<int>>& leftnode, shared_ptr<BST<int>>& rightnode){
	if(!leftnode&&!rightnode)
		return true;
	else if(leftnode&&rightnode){
		return leftnode->data==rightnode->data &&
				check_symmetric_tree_handler(leftnode->left,rightnode->right) &&
				check_symmetric_tree_handler(leftnode->right,rightnode->left);
	}
	else
		return false;
}
int main(){
	
}