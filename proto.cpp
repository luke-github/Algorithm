#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
};

pair<shared_ptr<BST<int>>,int> k_unbalanced_node(shared_ptr<BST<int>>& head, int k){
	if(!head){
		return {nullptr,0};
	}
	auto left_result = k_unbalanced_node(head->left,k);
	if(left_result.first)
		return left_result;
	auto right_result = k_unbalanced_node(head->right,k);
	if(right_result.first)
		return right_result;
	int num = left_result.second + right_result.second + 1;
	if(abs(left_result.second - right_result.second)>k){
		return {head,num};
	}
	return {nullptr,num};
}

int main(){
	
}