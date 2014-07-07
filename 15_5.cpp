#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
};

shared_ptr<BST<int>> LCA_Algorithm(shared_ptr<BST<int>>& root, shared_ptr<BST<int>>& s, shared_ptr<BST<int>>& b){
	shared_ptr<BST<int>> cur = root;
	while(((cur->data) < (s->data)) || ((cur->data) > (b->data))) {
		while((cur->data) < (s->data)){
			cur=cur->right;
		}
		while((cur->data) > (b->data)){
			cur=cur->left;
		}
	}
	return cur;
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
	shared_ptr<BST<int>> res = LCA_Algorithm(L1,L2,L5);
	cout<<res->data;
}


//     L1
//    /  \
//   L2  L3
//  /    / 
// L4   L5