#include <iostream>
#include <memory>
#include <vector>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
};

void k_largest_node_helper(shared_ptr<BST<int>>& head, int k, vector<int>* vec){
	if(vec->size()<k){
		k_largest_node_helper(head->right,k,vec);
		if(vec->size()<k){
			vec->emplace_back(head->data);
			k_largest_node_helper(head->left,k,vec);
		}
	}
}


vector<int> k_largest_node(shared_ptr<BST<int>>& head, int k){
	vector<int> res;
	k_largest_node_helper(head,k,&res);
	return res;
}

int main(){
	shared_ptr<BST<int>> L1 = make_shared<BST<int>>(BST<int>{5,nullptr,nullptr});
	shared_ptr<BST<int>> L2 = make_shared<BST<int>>(BST<int>{4,nullptr,nullptr});
	shared_ptr<BST<int>> L3 = make_shared<BST<int>>(BST<int>{7,nullptr,nullptr});
	shared_ptr<BST<int>> L4 = make_shared<BST<int>>(BST<int>{3,nullptr,nullptr});
	shared_ptr<BST<int>> L5 = make_shared<BST<int>>(BST<int>{6,nullptr,nullptr});
	L1->left = L2;
	L1->right = L3;
	L2->left = L4;
	L3->left = L5;
	vector<int> res = k_largest_node(L1,1);
	// for(int x : res)
	// 	cout<<x<<" ";
}