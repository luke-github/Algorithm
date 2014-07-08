#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
};

bool min_first_BSF_check(shared_ptr<BST<int>>& head, int k){
	if(!head||head->data>k){
		return false;
	}else if(head->data==k){
		return true;
	}else if(head->right&&k>=head->right->data){
		return min_first_BSF_check(head->right,k);
	}else{
		return min_first_BSF_check(head->left,k);
	}
}

int main(){
	
}