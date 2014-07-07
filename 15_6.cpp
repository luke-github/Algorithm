#include <iostream>
#include <memory>
#include <vector>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
};

shared_ptr<BST<int>> rebuild_BST_handler(vector<int>& vec, int low, int high, size_t* index){
	if(*index==vec.size()){
		return nullptr;
	}
	int cur = vec[*index];
	if(cur<low || cur>high){
		return nullptr;
	}
	++*index;
	return make_shared<BST<int>>(BST<int>{cur,rebuild_BST_handler(vec,low,cur,index),rebuild_BST_handler(vec,cur,high,index)});
}

shared_ptr<BST<int>> rebuild_BST(vector<int>& vec){
	size_t index = 0;
	return rebuild_BST_handler(vec,1<<31,(1<<31)-1,&index);
}

void pint_result(shared_ptr<BST<int>>& head){
	if(head==nullptr){
		return;
	}
	cout<<head->data<<"->";
	pint_result(head->left);
	pint_result(head->right);
}


int main(){
	vector<int> input = {5,3,2,4,6};
	shared_ptr<BST<int>> head = rebuild_BST(input);
	pint_result(head);
}