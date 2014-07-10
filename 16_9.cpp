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

vector<shared_ptr<BST<int>>> generate_all_tree_handler(int start, int end){
	vector<shared_ptr<BST<int>>> res;
	if(start>end){
		res.emplace_back(nullptr);
		return res;
	}
	for(int i=start;i<=end;i++){
		auto left_res = generate_all_tree_handler(start,i-1);
		auto right_res = generate_all_tree_handler(i+1,end);
		for(auto x : left_res){
			for(auto y : right_res){
				res.emplace_back(make_shared<BST<int>>(BST<int>{i,x,y}));
			}
		}
	}
	return res;
}

vector<shared_ptr<BST<int>>> generate_all_tree(int n){
	return generate_all_tree_handler(1,n);
}

int main(){
	auto res = generate_all_tree(5);
	for(auto x : res){
		cout<<x->data<<" ";
	}
}