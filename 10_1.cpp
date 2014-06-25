#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
};

int max_depty(shared_ptr<BST<int>>& head){
	if(!head){
		return 0;
	}else{
		return 1+max(max_depty(head->left),max_depty(head->right));
	}
}

int min_depty(shared_ptr<BST<int>>& head){
	if(!head){
		return 0;
	}else{
		return 1+min(min_depty(head->left),min_depty(head->right));
	}
}

bool balanced_tree(shared_ptr<BST<int>>& head){
	cout<<"Max Depty = "<<max_depty(head)<<endl;
	cout<<"Min Depty = "<<min_depty(head)<<endl;
	return max_depty(head)-min_depty(head) <=1;
}

int main(){
	shared_ptr<BST<int>> L1 = make_shared<BST<int>>(BST<int>{1,nullptr,nullptr});
	shared_ptr<BST<int>> L2 = make_shared<BST<int>>(BST<int>{2,nullptr,nullptr});
	shared_ptr<BST<int>> L3 = make_shared<BST<int>>(BST<int>{3,nullptr,nullptr});
	shared_ptr<BST<int>> L4 = make_shared<BST<int>>(BST<int>{4,nullptr,nullptr});
	shared_ptr<BST<int>> L5 = make_shared<BST<int>>(BST<int>{5,nullptr,nullptr});
	shared_ptr<BST<int>> L6 = make_shared<BST<int>>(BST<int>{6,nullptr,nullptr});
	shared_ptr<BST<int>> L7 = make_shared<BST<int>>(BST<int>{7,nullptr,nullptr});
	L1->left=L2;
	L1->right=L3;
	L2->left=L4;
	L2->right=L5;
	L3->left=L6;
	L5->right=L7;
	cout<<balanced_tree(L1);
}