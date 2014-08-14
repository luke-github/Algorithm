#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct BTN{
	T data;
	shared_ptr<BTN<T>> left;
	shared_ptr<BTN<T>> right;
};

void left_algo_func(shared_ptr<BTN<int>>& node, bool is_boundary){
	if(node){
		if(is_boundary || (!node->left&&!node->right)){
			cout<<node->data<<" ";
		}
		left_algo_func(node->left,is_boundary);
		left_algo_func(node->right,is_boundary&&!node->left);
	}
}

void right_algo_func(shared_ptr<BTN<int>>& node, bool is_boundary){
	if(node){
		right_algo_func(node->left,is_boundary&&!node->right);
		right_algo_func(node->right,is_boundary);
		if(is_boundary || (!node->left&&!node->right)){
			cout<<node->data<<" ";
		}
	}
}

void print_exterior(shared_ptr<BTN<int>>& root){
	if(root){
		cout<<root->data<<" ";
		left_algo_func(root->left,true);
		right_algo_func(root->right,true);
	}
}

int main(){
	shared_ptr<BTN<int>> T1 = make_shared<BTN<int>>(BTN<int>{1,nullptr,nullptr});
	shared_ptr<BTN<int>> T2 = make_shared<BTN<int>>(BTN<int>{2,nullptr,nullptr});
	shared_ptr<BTN<int>> T3 = make_shared<BTN<int>>(BTN<int>{3,nullptr,nullptr});
	shared_ptr<BTN<int>> T4 = make_shared<BTN<int>>(BTN<int>{4,nullptr,nullptr});
	shared_ptr<BTN<int>> T5 = make_shared<BTN<int>>(BTN<int>{5,nullptr,nullptr});
	shared_ptr<BTN<int>> T6 = make_shared<BTN<int>>(BTN<int>{6,nullptr,nullptr});
	T1->left=T2;
	T1->right=T3;
	T2->left=T4;
	T2->right=T5;
	T3->left=T6;
	print_exterior(T1);
}