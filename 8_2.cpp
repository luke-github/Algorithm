#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> reverse_link_list(shared_ptr<ListNode<int>>& head){
	shared_ptr<ListNode<int>> cur=head,pre=nullptr;
	while(cur){
		shared_ptr<ListNode<int>> temp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = temp;
	}
	return pre;
}

int main(){
	
}


// void test_func(ListNode<int> m){
// 	cout<<m.data;
// }

// int main(){
// 	shared_ptr<ListNode<int>> L1 =
//     make_shared<ListNode<int>>(ListNode<int>{1, nullptr});
//     shared_ptr<ListNode<int>> L2 =
//     make_shared<ListNode<int>>(ListNode<int>{2, nullptr});
//     L1->next=L2;
//     // test_func(L1);
//     ListNode<int> node1;
//     node1.data=10;
//     test_func(node1);
// }