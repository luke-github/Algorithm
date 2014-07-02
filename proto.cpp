#include <iostream>
#include <memory>
#include <unordered_set>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> left;
	shared_ptr<ListNode<T>> right;
	shared_ptr<ListNode<T>> parent;
};

shared_ptr<ListNode<int>> LCA(shared_ptr<ListNode<int>>& a, shared_ptr<ListNode<int>>& b){
	unordered_set<shared_ptr<ListNode<int>>> hash;
	while(a||b){
		if(a){
			if(hash.emplace(a).second==false){
				return a;
			}
			a=a->parent;
		}
		if(b){
			if(hash.emplace(b).second==false){
				return b;
			}
			b=b->parent;
		}
	}
	throw invalid_argument("invalid");
}
int main(){
	
}