#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
};

shared_ptr<BST<int>> larger_than_k(shared_ptr<BST<int>>& head, int k){
	shared_ptr<BST<int>> cur = head, res = nullptr;
	bool found = false;
	while(cur){
		if(cur->data==k){
			found=true;
			cur=cur->right;
		}else if(cur->data>k){
			res = cur;
			cur=cur->left;
		}else{
			cur=cur->right;
		}
	}
	return found?res:nullptr;
}
int main(){
	
}