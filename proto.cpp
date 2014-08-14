#include <stack>
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

template<class T>
struct BTN{
	T data;
	shared_ptr<BTN<T>> left;
	shared_ptr<BTN<T>> right;
};

vector<int> preorder_iteration(shared_ptr<BTN<int>>& root){
	if(!root){
		return {};
	}
	stack<shared_ptr<BTN<int>>> s;
	vector<int> res;
	s.emplace(root);
	while(!s.empty()){
		auto cur = s.top();
		s.pop();
		res.emplace_back(cur->data);
		if(cur->right){
			s.emplace(cur->right);
		}
		if(cur->left){
			s.emplace(cur->left);
		}
	}
	return res;
}

int main(){
	
}