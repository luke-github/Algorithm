#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
	shared_ptr<BST<T>> parent;
};

int depth(shared_ptr<BST<int>> node){
	int count=0;
	while(node){
		count++;
		node=node->parent;
	}
	return count;
}

shared_ptr<BST<int>> LCA(shared_ptr<BST<int>>& A,shared_ptr<BST<int>>& B){
	auto p1 = A;
	auto p2 = B;
	int depth_a = depth(A);
	int depth_b = depth(B);
	if(depth_b>depth_a)
		swap(p1,p2);
	int diff = abs(depth_a - depth_b);
	while(diff--){
		p1=p1->parent;
	}
	while(p1!=p2){
		p1=p1->parent;
		p2=p2->parent;
	}
	return p1;
}

int main(){
	shared_ptr<BST<int>> L1 = make_shared<BST<int>>(BST<int>{1,nullptr,nullptr,nullptr});
	shared_ptr<BST<int>> L2 = make_shared<BST<int>>(BST<int>{2,nullptr,nullptr,nullptr});
	shared_ptr<BST<int>> L3 = make_shared<BST<int>>(BST<int>{3,nullptr,nullptr,nullptr});
	shared_ptr<BST<int>> L4 = make_shared<BST<int>>(BST<int>{4,nullptr,nullptr,nullptr});
	shared_ptr<BST<int>> L5 = make_shared<BST<int>>(BST<int>{5,nullptr,nullptr,nullptr});
	shared_ptr<BST<int>> L6 = make_shared<BST<int>>(BST<int>{6,nullptr,nullptr,nullptr});
	L1->left=L2;
	L1->right=L3;
	L2->left=L4;
	L2->right=L5;
	L5->right=L6;
	L2->parent=L1;
	L3->parent=L1;
	L4->parent=L2;
	L5->parent=L2;
	L6->parent=L5;
	cout<<LCA(L6,L4)->data;
}