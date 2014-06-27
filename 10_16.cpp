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

void set_next(shared_ptr<BSF_Node<int>>& head){
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
	shared_ptr<BSF_Node<int>> L1 = make_shared<BSF_Node<int>>(BSF_Node<int>{1,nullptr,nullptr,nullptr});
	shared_ptr<BSF_Node<int>> L2 = make_shared<BSF_Node<int>>(BSF_Node<int>{2,nullptr,nullptr,nullptr});
	shared_ptr<BSF_Node<int>> L3 = make_shared<BSF_Node<int>>(BSF_Node<int>{3,nullptr,nullptr,nullptr});
	shared_ptr<BSF_Node<int>> L4 = make_shared<BSF_Node<int>>(BSF_Node<int>{4,nullptr,nullptr,nullptr});
	shared_ptr<BSF_Node<int>> L5 = make_shared<BSF_Node<int>>(BSF_Node<int>{5,nullptr,nullptr,nullptr});	
	L1->left=L2;
	L1->right=L3;
	L2->left=L4;
	L2->right=L5;
	set_next(L1);
	cout<<L2->next->data<<endl;
	cout<<L4->next->data<<endl;

}