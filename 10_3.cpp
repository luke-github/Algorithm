// recursion usually can be used for solving BST problems.
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
	if(!leftnode&&!rightnode){
		return true;
	}
	else if(leftnode&&rightnode){
		return leftnode->data==rightnode->data &&
				check_symmetric_tree_handler(leftnode->left,rightnode->right) &&
				check_symmetric_tree_handler(leftnode->right,rightnode->left);
	}
	else
		return false;
}

int main(){
	shared_ptr<BST<int>> L1 = make_shared<BST<int>>(BST<int>{1,nullptr,nullptr});
	shared_ptr<BST<int>> L2 = make_shared<BST<int>>(BST<int>{2,nullptr,nullptr});
	shared_ptr<BST<int>> L3 = make_shared<BST<int>>(BST<int>{2,nullptr,nullptr});
	shared_ptr<BST<int>> L4 = make_shared<BST<int>>(BST<int>{4,nullptr,nullptr});
	shared_ptr<BST<int>> L5 = make_shared<BST<int>>(BST<int>{4,nullptr,nullptr});
	shared_ptr<BST<int>> L6 = make_shared<BST<int>>(BST<int>{6,nullptr,nullptr});
	shared_ptr<BST<int>> L7 = make_shared<BST<int>>(BST<int>{7,nullptr,nullptr});	
	shared_ptr<BST<int>> L8 = make_shared<BST<int>>(BST<int>{8,nullptr,nullptr});
	shared_ptr<BST<int>> L9 = make_shared<BST<int>>(BST<int>{9,nullptr,nullptr});
	L1->left=L2;
	L1->right=L3;
	L2->right=L4;
	L3->left=L5;
	L5->left=L6;
	cout<<check_symmetric_tree(L1);
}