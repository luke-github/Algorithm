#include <iostream>
#include <memory>
#include <list>
using namespace std;

template<class T>
struct BSF_Node{
	T data;
	shared_ptr<BSF_Node<T>> left;
	shared_ptr<BSF_Node<T>> right;
	shared_ptr<BSF_Node<T>> next;
};

void set_next_link(shared_ptr<BSF_Node<int>>& head){
	shared_ptr<BSF_Node<int>> left_first=head;
	shared_ptr<BSF_Node<int>> parent=nullptr;
	while(left_first){
		parent=left_first;
		while(parent&&parent->left){
			parent->left->next=parent->right;
			if(parent->next){
				parent->right->next=parent->next->left;
			}
			parent=parent->next;
		}
		left_first=left_first->left;
	}
}
int main(){
	
}