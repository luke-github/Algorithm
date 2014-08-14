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
	s.emplace(root);
	vector<int> res;
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
	auto res = preorder_iteration(T1);
	for(int x : res){
		cout<<x<<" ";
	}
}