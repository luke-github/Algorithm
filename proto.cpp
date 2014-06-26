#include <iostream>
#include <memory>
#include <vector>
#include <stack>
using namespace std;

template<class T>
struct BST_Node{
	T data;
	shared_ptr<BST_Node<T>> left;
	shared_ptr<BST_Node<T>> right;
};

shared_ptr<BST_Node<int>> reconstruct_BST(vector<int>& preorder){
	stack<shared_ptr<BST_Node<int>>> st;
	reverse(preorder.begin(),preorder.end());
	for(auto it = preorder.begin();it!=preorder.end();it++){
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

void print_result(shared_ptr<BST_Node<int>>& head){
	if(!head){
		return;
	}
	if(head->left){
		print_result(head->left);
	}
	cout<<head->data<<" ";
	if(head->right){
		print_result(head->right);
	}
}

int main(){
	vector<int> input = {1,2,4,0,0,5,0,0,3,0,0};
	shared_ptr<BST_Node<int>> head = reconstruct_BST(input);
	print_result(head);
}
//    L1
//   /  \
//  L2  L3
//  / \
// L4 L5