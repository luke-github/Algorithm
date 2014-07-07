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

bool continue_search(shared_ptr<BST<int>> p, shared_ptr<BST<int>> t, shared_ptr<BST<int>> m, bool found_m){
	while(p && p!=t){
		if(p==m){
			found_m=true;
		}
		p = p->data>t->data?p->left:p->right;
	}
	return p==t && found_m;
}

bool ancestor_descendant_checker(shared_ptr<BST<int>>& r, shared_ptr<BST<int>>& s, shared_ptr<BST<int>>& m){
	auto cur_r = r, cur_s = s;
	bool found_m=false;
	while(cur_r && cur_r!= s && cur_s && cur_s!= r){
		if(cur_r==m){
			found_m=true;
		}else if(cur_s==m){
			found_m=true;
		}
		cur_r = cur_r->data>s->data?cur_r->left:cur_r->right;
		cur_s = cur_s->data>r->data?cur_s->left:cur_s->right;
	}
	if(cur_r==s||cur_s==r){
		return false;
	}
	return continue_search(cur_r,s,m,found_m) || continue_search(cur_s,r,m,found_m);
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
	cout<<ancestor_descendant_checker(L1,L5,L3);
}