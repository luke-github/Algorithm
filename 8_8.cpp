#include <iostream>
#include <memory>
using namespace std;

void delete_node(shared_ptr<ListNode<int>>& v){
	v->data=v->next->data;
	v->next=v->next->next;
}