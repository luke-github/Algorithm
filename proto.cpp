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

shared_ptr<BST<int>> build_BSF_handler(vector<int>& vec, int start,int end){
	if(start<end){
		int mid = (start+end)>>1;
		return make_shared<BST<int>>(BST<int>{vec[mid],build_BSF_handler(vec,start,mid),build_BSF_handler(vec,mid+1,end)});
	}
	return nullptr;
}

shared_ptr<BST<int>> build_BSF(vector<int>& vec){
	return build_BSF_handler(vec,0,vec.size());
}

void print_result(shared_ptr<BST<int>>& head){
	if(head==nullptr){
		return;
	}
	cout<<head->data<<"->";
	print_result(head->left);
	print_result(head->right);
}

int main(){
	vector<int> input = {1,2,3,4,5,6,7,8,9};
	shared_ptr<BST<int>> res = build_BSF(input);
	print_result(res);
}