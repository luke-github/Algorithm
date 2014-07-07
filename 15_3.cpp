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
	while(cur!=nullptr){
		if(cur->data==k){
			found=true;
			cur=cur->right;
		}else if(cur->data<k){
			cur=cur->right;
		}else{
			res = cur;
			cur=cur->left;
		}
	}
	return found?res:nullptr;
}

int main(){
	shared_ptr<BST<int>> L1 = make_shared<BST<int>>(BST<int>{5,nullptr,nullptr});
	shared_ptr<BST<int>> L2 = make_shared<BST<int>>(BST<int>{4,nullptr,nullptr});
	shared_ptr<BST<int>> L3 = make_shared<BST<int>>(BST<int>{7,nullptr,nullptr});
	shared_ptr<BST<int>> L4 = make_shared<BST<int>>(BST<int>{3,nullptr,nullptr});
	shared_ptr<BST<int>> L5 = make_shared<BST<int>>(BST<int>{6,nullptr,nullptr});
	L1->left = L2;
	L1->right = L3;
	L2->left = L4;
	L3->left = L5;
	shared_ptr<BST<int>> res = larger_than_k(L1,6);
	cout<<res->data;
}

//     L1
//    /  \
//   L2  L3
//  /    / 
// L4   L5
