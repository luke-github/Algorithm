#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<int>> next;
};

shared_ptr<ListNode<int>> reverse_sublist(shared_ptr<ListNode<int>> L, int start, int end){
	if(start==end){
		return L;
	}
	size_t count=1;
	shared_ptr<ListNode<int>> start_ptr=L, pre_start_ptr=nullptr;
	while(count<start){
		count++;
		pre_start_ptr = start_ptr;
		start_ptr = start_ptr->next;
	}
	if(pre_start_ptr){
		pre_start_ptr->next=nullptr;
	}
	shared_ptr<ListNode<int>> cur=start_ptr,pre=nullptr,end_ptr=nullptr,next_end_ptr=nullptr;
	while(count<end){
		count++;
		end_ptr=cur->next;
		next_end_ptr = end_ptr->next;
		cur->next = pre;
		pre = cur;
		cur = end_ptr;
	}
	end_ptr->next = pre;
	start_ptr->next=next_end_ptr;
	if(pre_start_ptr){
		pre_start_ptr->next=end_ptr;
		return L;
	}else{
		return end_ptr;
	}

}
int main(){
	
}