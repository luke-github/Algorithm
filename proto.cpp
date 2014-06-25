#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
};

shared_ptr<BST<int>> LCA(shared_ptr<BST<int>>& root,shared_ptr<BST<int>>& A, shared_ptr<BST<int>>& B){
	if(!root){
		return nullptr;
	}
	else if(root==A||root==B){
		return root;
	}
	 shared_ptr<BST<int>> left_result = LCA(root->left,A,B);
	 shared_ptr<BST<int>> right_result = LCA(root->right,A,B);
	if(left_result&&right_result){
		return root;
	}else{
		return left_result? left_result : right_result;
	}
}
int main(){
	
}