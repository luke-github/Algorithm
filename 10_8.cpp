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

shared_ptr<BST_Node<int>> kth_node(shared_ptr<BST_Node<int>>& head, int k){
	shared_ptr<BST_Node<int>> p = head;
	while(p){
		int left_size = p->left? p->left->size:0; 
		if(left_size<k-1){
			k=k-(left_size+1);
			p=p->right;
		}
		else if(left_size==k-1)
			return p;
		else
			p=p->left;
	}
	throw invalid_argument("invalid_node");
}

int main(){

}