#include <iostream>
#include <memory>
#include <vector>
#include <unordered_map>
using namespace std;

template<class T>
struct BST_Node{
	T data;
	shared_ptr<BST_Node<T>> left;
	shared_ptr<BST_Node<T>> right;
};

shared_ptr<BST_Node<int>> construct_inorder_BST(vector<int>& preorder,vector<int>& inorder){
	unordered_map<int,size_t> in_entry_index_map;
	for(int i=0;i<in.size();i++)
		in_entry_index_map.emplace(inorder[i],i);
	return construct_inorder_BST_handler(preorder,0,preorder.size(),inorder,0,inorder.size(),in_entry_index_map);
}

construct_inorder_BST_handler()