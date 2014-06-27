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
void generate_leave_node_list_handler(shared_ptr<BSF_Node<int>>& node, list<shared_ptr<BSF_Node<int>>>* result);
list<shared_ptr<BSF_Node<int>>> generate_leave_node_list(shared_ptr<BSF_Node<int>>& head){
	list<shared_ptr<BSF_Node<int>>> return_list;
	generate_leave_node_list_handler(head,&return_list);
	return return_list;
}

void generate_leave_node_list_handler(shared_ptr<BSF_Node<int>>& node, list<shared_ptr<BSF_Node<int>>>* result){
	if(node){
		if(!node->left&&!node->right){
			result->emplace_back(node);
		}else{
			generate_leave_node_list_handler(node->left,result);
			generate_leave_node_list_handler(node->right,result);
		}
	}
}

int main(){
	
}

