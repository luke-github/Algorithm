#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct BST_Node{
	T data;
	shared_ptr<BST_Node<T>> left;
	shared_ptr<BST_Node<T>> right;
	T size;
};

shared_ptr<BST_Node<int>> find_node(shared_ptr<BST_Node<int>> head, int k){
	while(head){
		int left_size = head->left? head->left->size : 0;
		if(left_size<k-1){
			k-=(left_size+1);
			head=head->right;
		}
		else if(left_size==k-1)
			return head;
		else{
			head = head->left;
		}
	}
	throw invalid_argument("invalid node");
}
int main(){
	
}