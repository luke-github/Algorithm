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
shared_ptr<BST_Node<int>> construct_inorder_BST_handler(vector<int>& pre, int pre_s, int pre_e, vector<int>& in, int in_s, int in_e, unordered_map<int, size_t> in_entry_index_map);
shared_ptr<BST_Node<int>> construct_inorder_BST(vector<int>& preorder,vector<int>& inorder){
	unordered_map<int,size_t> in_entry_index_map;
	for(int i=0;i<inorder.size();i++)
		in_entry_index_map.emplace(inorder[i],i);
	return construct_inorder_BST_handler(preorder,0,preorder.size(),inorder,0,inorder.size(),in_entry_index_map);
}

shared_ptr<BST_Node<int>> construct_inorder_BST_handler(vector<int>& pre, int pre_s, int pre_e, vector<int>& in, int in_s, int in_e, unordered_map<int, size_t> in_entry_index_map){
	if(pre_e>pre_s&&in_e>in_s){
		int index = in_entry_index_map.at(pre[pre_s]);
		int left_part = index - in_s;
		return make_shared<BST_Node<int>>(BST_Node<int>({pre[pre_s],
			construct_inorder_BST_handler(pre,pre_s+1,pre_s+1+left_part,in,in_s,index,in_entry_index_map),
			construct_inorder_BST_handler(pre,pre_s+1+left_part,pre_e,in,index+1,in_e,in_entry_index_map)}));
	}
	return nullptr;
}

int main(){

}