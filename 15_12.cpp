#include <iostream>
#include <vector>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
};

shared_ptr<BST<int>> DoubleList_algo(shared_ptr<BST<int>>& T){
	if(!T){
		return nullptr;
	}
	auto l_head = DoubleList_algo(T->left);
	auto r_head = DoubleList_algo(T->right);
	
	// link T to l list
	shared_ptr<BST<int>> l_tail = nullptr;
	if(l_head){
		l_tail = l_head->left;
		l_tail->right = T;
		T->left = l_tail;
		l_tail = T;
	}else{
		l_head = l_tail = T;
	}

	// link t to righth list
	shared_ptr<BST<int>> r_tail = nullptr;
	if(r_head){
		r_tail = r_head->left;
		l_tail->right = r_head;
		r_head->left = l_tail;
	}else{
		r_tail = r_head;
	}

	// link together

	l_head->left = r_tail;
	r_tail->right = l_head;
	return l_head;

}

shared_ptr<BST<int>> BST_DoubleList(shared_ptr<BST<int>>& T){
	auto res = DoubleList_algo(T);
	res->left->right = nullptr;
	res->left = nullptr;
	return res;
}

int main(){
	shared_ptr<BST<int>> T1 = make_shared<BST<int>>(BST<int>{1,nullptr,nullptr});
	shared_ptr<BST<int>> T2 = make_shared<BST<int>>(BST<int>{2,nullptr,nullptr});
	shared_ptr<BST<int>> T3 = make_shared<BST<int>>(BST<int>{3,nullptr,nullptr});
	shared_ptr<BST<int>> T4 = make_shared<BST<int>>(BST<int>{1,nullptr,nullptr});
	shared_ptr<BST<int>> T5 = make_shared<BST<int>>(BST<int>{5,nullptr,nullptr});
	shared_ptr<BST<int>> T11 = make_shared<BST<int>>(BST<int>{11,nullptr,nullptr});
	shared_ptr<BST<int>> T7 = make_shared<BST<int>>(BST<int>{7,nullptr,nullptr});
	T7->left = T3;
	T7->right = T11;
	T3->left = T2;
	T3->right = T5;
	auto res = BST_DoubleList(T7);
}

