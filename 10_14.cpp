#include <iostream>
#include <memory>
#include <list>
using namespace std;

template<class T>
struct BSF_Node{
	T data;
	shared_ptr<BSF_Node<T>> left;
	shared_ptr<BSF_Node<T>> right;
};
void generate_leave_list_handler(shared_ptr<BSF_Node<int>>& node, list<shared_ptr<BSF_Node<int>>>* result);
list<shared_ptr<BSF_Node<int>>> generate_leave_list(shared_ptr<BSF_Node<int>>& head){
	list<shared_ptr<BSF_Node<int>>> L;
	generate_leave_list_handler(head,&L);
	return L;
}

void generate_leave_list_handler(shared_ptr<BSF_Node<int>>& node, list<shared_ptr<BSF_Node<int>>>* result){
	if(node){
		if(!node->left&&!node->right){
			result->emplace_back(node);
		}
		else{
			generate_leave_list_handler(node->left,result);
			generate_leave_list_handler(node->right,result);
		}
	}
}

int main(){
	shared_ptr<BSF_Node<int>> L1 = make_shared<BSF_Node<int>>(BSF_Node<int>{1,nullptr,nullptr});
	shared_ptr<BSF_Node<int>> L2 = make_shared<BSF_Node<int>>(BSF_Node<int>{2,nullptr,nullptr});
	shared_ptr<BSF_Node<int>> L3 = make_shared<BSF_Node<int>>(BSF_Node<int>{3,nullptr,nullptr});
	shared_ptr<BSF_Node<int>> L4 = make_shared<BSF_Node<int>>(BSF_Node<int>{4,nullptr,nullptr});
	shared_ptr<BSF_Node<int>> L5 = make_shared<BSF_Node<int>>(BSF_Node<int>{5,nullptr,nullptr});
	L1->left=L2;
	L1->right=L3;
	L2->left=L4;
	L3->right=L5;
	list<shared_ptr<BSF_Node<int>>> res = generate_leave_list(L1);
	for(auto it=res.begin();it!=res.end();it++){
		cout<<(*it)->data<<" ";
	}
}