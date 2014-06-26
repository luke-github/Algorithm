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
void print_result(shared_ptr<BST_Node<int>>& node);
shared_ptr<BST_Node<int>> reconstruct_inorder_handler(vector<int>& pre, int pre_s, int pre_e, vector<int>& in, int in_s, int in_e, unordered_map<int, size_t>& in_entry_map);
shared_ptr<BST_Node<int>> reconstruct_inorder(vector<int>& pre, vector<int>& in){
	unordered_map<int, size_t> in_entry_map;
	for(int i=0;i<in.size();i++){
		in_entry_map.emplace(in[i],i);
	}
	return reconstruct_inorder_handler(pre,0,pre.size(),in,0,in.size(),in_entry_map);
}

shared_ptr<BST_Node<int>> reconstruct_inorder_handler(vector<int>& pre, int pre_s, int pre_e, vector<int>& in, int in_s, int in_e, unordered_map<int, size_t>& in_entry_map){
	if(pre_e>pre_s&&in_e>in_s){
		auto index = in_entry_map.at(pre[pre_s]);
		auto left_tree = index - in_s;
		return make_shared<BST_Node<int>>(BST_Node<int>{pre[pre_s],reconstruct_inorder_handler(pre,pre_s+1,pre_s+1+left_tree,in,in_s,index,in_entry_map),reconstruct_inorder_handler(pre,pre_s+1+left_tree,pre_e,in,index+1,in_e,in_entry_map)});
	}
	return nullptr;
}


void print_result(shared_ptr<BST_Node<int>>& node){
	if(!node){
		return;
	}
	if(node->left)
		print_result(node->left);
	cout<<node->data<<":";
	if(node->right)
		print_result(node->right);
}

int main(){
	vector<int> inorder = {2,1,4,3,5};
	vector<int> preorder = {1,2,3,4,5};
	shared_ptr<BST_Node<int>> result = reconstruct_inorder(preorder,inorder);
	print_result(result);
}