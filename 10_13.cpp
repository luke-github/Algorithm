#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#define NULL 0
using namespace std;

template<class T>
struct BST_Node{
	T data;
	shared_ptr<BST_Node<T>> left;
	shared_ptr<BST_Node<T>> right;
};

shared_ptr<BST_Node<int>> reconstruct_BST(vector<int>& pre_vec){
	stack<shared_ptr<BST_Node<int>> > st;
	reverse(pre_vec.begin(),pre_vec.end());
	for(auto it=pre_vec.begin();it!=pre_vec.end();it++){
		if(!*it){
			st.emplace(nullptr);
		}else{
			shared_ptr<BST_Node<int>> left = st.top();
			st.pop();
			shared_ptr<BST_Node<int>> right = st.top();
			st.pop();
			st.emplace(make_shared<BST_Node<int>>(BST_Node<int>{*it,left,right}));
		}
	}
	return st.top();
}

void print_tree(shared_ptr<BST_Node<int>>& node){
	if(!node){
		return;
	}
	if(node->left)
		print_tree(node->left);
	cout<<node->data<<" ";
	if(node->right)
		print_tree(node->right);
}

int main(){
	vector<int> input = {1,2,4,NULL,NULL,5,NULL,NULL,3,NULL,NULL};
	shared_ptr<BST_Node<int>> result = reconstruct_BST(input);
	print_tree(result);

}

//    L1
//   /  \
//  L2  L3
//  / \
// L4 L5