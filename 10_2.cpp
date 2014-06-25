#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
};

pair<shared_ptr<BST<int>>,int> k_unbalanced_node_handler(shared_ptr<BST<int>>& head, int k){
	if(!head){
		return {nullptr,0};
	}
	auto left_result = k_unbalanced_node_handler(head->left,k);
	if(left_result.first)
		return left_result;
	auto right_result = k_unbalanced_node_handler(head->right,k);
	if(right_result.first)
		return right_result;
	int num = left_result.second + right_result.second + 1;
	if(abs(left_result.second - right_result.second)>k){
		return {head,num};
	}
	return {nullptr,num};
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
	L2->right=L4;
	L4->left=L5;
	L5->right=L6;
	L4->right=L7;
	L3->right=L8;
	pair<shared_ptr<BST<int>>,int> result = k_unbalanced_node_handler(L1,3);
	cout<<result.first->data<<" "<<result.second;
}