#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<int>> next;
};

double find_median(shared_ptr<ListNode<int>>& ptr){
	shared_ptr<ListNode<int>> cur=ptr, start=ptr;
	int count=0;
	do{
		count++;
		cur=cur->next;
		if(start->data>cur->data)
			start=cur;
	}while(cur!=ptr);
	for(int i=0;i<(count-1)/2;i++){
		start=start->next;
	}
	return count&1?start->data:0.5*(start->data+start->next->data);
}
int main(){
	
}