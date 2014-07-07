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

bool continue_search(shared_ptr<BST<int>> p, shared_ptr<BST<int>> t, shared_ptr<BST<int>>& m){
	while(p!=t && p){
		p = p->data>t->data ? p->left : p->right;
	}
	return p==m;
}

bool descendant_ancestor_checker(shared_ptr<BST<int>>& r,shared_ptr<BST<int>>& s, shared_ptr<BST<int>>& m){
	auto cur_r = r, cur_s = s;
	while(cur_r && cur_r!=s && cur_s && cur_s!= r){
		if(cur_r==m||cur_s==m){
			return true;
		}
		cur_r=cur_r->data>s->data?r->left:r->right;
		cur_s=cur_s->data>r->data?cur_s->left:cur_s->right;
	}
	if(cur_r==s||cur_s==r){
		return false;
	}
	return continue_search(cur_r,s,m) || continue_search(cur_s,r,m);
}