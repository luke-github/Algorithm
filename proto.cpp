#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> reverse_list(shared_ptr<ListNode<int>>& L){
	shared_ptr<ListNode<int>> cur=L, pre=nullptr;
	while(cur){
		shared_ptr<ListNode<int>> temp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = temp;
	}
	return pre;
}

shared_ptr<ListNode<int>> reverse_k(shared_ptr<ListNode<int>>& L, int k){
	shared_ptr<ListNode<int>> before_pre=nullptr,before_post=nullptr,pre=L,post=L;
	bool first_time =  true;
	while(pre){
		int i=k;
		while(i){
			i--;
			before_post=post;
			post=post->next;
			if(!post)
				break;
		}
		if(i){
			return L;
		}
		before_post->next = nullptr;
		reverse_list(pre);
		if(before_pre){
			before_pre->next=before_post;
		}
		if(first_time){
			L=before_post;
			first_time=false;
		}
		before_pre = pre;
		pre->next = post;
		pre = post;
		before_post = nullptr;
	}
	return L;
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
	L4->next=L5;
	shared_ptr<ListNode<int>> result = reverse_k(L1,2);
	while(result){
		cout<<result->data<<" ";
		result=result->next;
	}
}