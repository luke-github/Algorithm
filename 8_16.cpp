#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<int>> next;
};

double median_result(shared_ptr<ListNode<int>>& ptr){
	shared_ptr<ListNode<int>> start_ptr=ptr, cur=ptr;
	int length=0;
	do{
		cur=cur->next;
		length++;
		if(cur->data<=start_ptr->data){
			start_ptr=cur;
		}
	}while(cur!=ptr);


	cout<<start_ptr->data<<" "<<length<<endl;
	for(int i=0;i<((length-1)/2);i++){
		start_ptr=start_ptr->next;
	}
	return length&1?start_ptr->data:0.5*(start_ptr->data+start_ptr->next->data);
}

int main(){
	shared_ptr<ListNode<int>> L1 = make_shared<ListNode<int>>(ListNode<int>{1,nullptr});
	shared_ptr<ListNode<int>> L2 = make_shared<ListNode<int>>(ListNode<int>{2,nullptr});
	shared_ptr<ListNode<int>> L3 = make_shared<ListNode<int>>(ListNode<int>{3,nullptr});
	shared_ptr<ListNode<int>> L4 = make_shared<ListNode<int>>(ListNode<int>{4,nullptr});
	shared_ptr<ListNode<int>> L5 = make_shared<ListNode<int>>(ListNode<int>{5,nullptr});
	L1->next=L2;
	L2->next=L3;
	L3->next=L4;
	L4->next=L1;
	L5->next=L1;
	cout<<median_result(L3);
}