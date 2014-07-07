#include <iostream>
#include <memory>
#include <numeric>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
};

bool is_BST_helper(shared_ptr<BST<int>>& head,int minimal,int maximum);

bool is_BST(shared_ptr<BST<int>>& head){
	return is_BST_helper(head,1<<31,(1<<31)-1);
}

bool is_BST_helper(shared_ptr<BST<int>>& head,int minimal,int maximum){
	if(head==nullptr){
		return true;
	}
	if(head->data<minimal || head->data>maximum){
		return false;
	}
	return is_BST_helper(head->left,minimal,head->data) && is_BST_helper(head->right,head->data,maximum);
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
	cout<<is_BST(L1);
}

//     L1
//    /  \
//   L2  L3
//  /    / 
// L4   L5

