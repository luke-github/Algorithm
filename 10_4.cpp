#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
};

shared_ptr<BST<int>> LCA(shared_ptr<BST<int>>& root, shared_ptr<BST<int>>& A, shared_ptr<BST<int>>& B){
	if(!root){
		return nullptr;
	}
	else if(root==A || root==B){
		return root;
	}
	auto left_result = LCA(root->left,A,B);
	auto right_result = LCA(root->right,A,B);
	if(left_result&&right_result){
		return root;
	}
	else{
		return left_result? left_result : right_result;
	}
}

int main(){
	shared_ptr<BST<int>> L1 = make_shared<BST<int>>(BST<int>{1,nullptr,nullptr});
	shared_ptr<BST<int>> L2 = make_shared<BST<int>>(BST<int>{2,nullptr,nullptr});
	shared_ptr<BST<int>> L3 = make_shared<BST<int>>(BST<int>{3,nullptr,nullptr});
	shared_ptr<BST<int>> L4 = make_shared<BST<int>>(BST<int>{4,nullptr,nullptr});
	shared_ptr<BST<int>> L5 = make_shared<BST<int>>(BST<int>{5,nullptr,nullptr});
	shared_ptr<BST<int>> L6 = make_shared<BST<int>>(BST<int>{6,nullptr,nullptr});
	shared_ptr<BST<int>> L7 = make_shared<BST<int>>(BST<int>{7,nullptr,nullptr});	
	shared_ptr<BST<int>> L8 = make_shared<BST<int>>(BST<int>{8,nullptr,nullptr});
	shared_ptr<BST<int>> L9 = make_shared<BST<int>>(BST<int>{9,nullptr,nullptr});
	L1->left=L2;
	L1->right=L3;
	L2->left=L4;
	L2->right=L5;
	L4->left=L6;
	L4->right=L7;
	shared_ptr<BST<int>> result = LCA(L1,L6,L7);
	cout<<result->data;
}