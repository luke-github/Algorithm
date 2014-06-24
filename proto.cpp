#include <iostream>
#include <memory>
#include <queue>
using namespace std;

template<class T>
struct Node{
	T data;
	shared_ptr<Node<int>> left;
	shared_ptr<Node<int>> right;
};

void print_binary_tree(shared_ptr<Node<int>>& head){
	if(!head){
		return;
	}
	queue<shared_ptr<Node<int>>> q;
	q.emplace(head);
	int count = q.size();
	while(!q.empty()){
		cout<<q.front()->data<<" ";
		shared_ptr<Node<int>> temp = q.front();
		if(temp->left){
			q.emplace(temp->left);
		}
		if(temp->right){
			q.emplace(temp->right);
		}
		q.pop();
		if(--count==0){
			count=q.size();
			cout<<endl;
		}
	}
}

int main(){
	shared_ptr<Node<int>> L1 = make_shared<Node<int>>(Node<int>{1,nullptr,nullptr});
	shared_ptr<Node<int>> L2 = make_shared<Node<int>>(Node<int>{2,nullptr,nullptr});
	shared_ptr<Node<int>> L3 = make_shared<Node<int>>(Node<int>{3,nullptr,nullptr});
	shared_ptr<Node<int>> L4 = make_shared<Node<int>>(Node<int>{4,nullptr,nullptr});
	shared_ptr<Node<int>> L5 = make_shared<Node<int>>(Node<int>{5,nullptr,nullptr});
	shared_ptr<Node<int>> L6 = make_shared<Node<int>>(Node<int>{6,nullptr,nullptr});
	shared_ptr<Node<int>> L7 = make_shared<Node<int>>(Node<int>{7,nullptr,nullptr});
	shared_ptr<Node<int>> L8 = make_shared<Node<int>>(Node<int>{8,nullptr,nullptr});
	L1->left=L2;
	L1->right=L3;
	L2->left=L4;
	L2->right=L5;
	L3->left=L6;
	L3->right=L7;
	L4->left=L8;
	print_binary_tree(L1);
}