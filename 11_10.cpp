#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp{
	bool operator ()(const pair<int,int>& a, const pair<int,int>& b){
		return a.first<b.first;
	}
};

class My_Stack{
public:
	void push(int x){
		max_heap_.emplace(order_++,x);
	}
	int pop(){
		int res = max_heap_.top().second;
		max_heap_.pop();
		return res;
	}
	int peek(){
		return max_heap_.top().second;
	}
private:
	priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> max_heap_;
	int order_=0;
};

class My_Queue{
public:
	void push(int x){
		max_heap_.emplace(order_--,x);
	}
	int pop(){
		int res = max_heap_.top().second;
		max_heap_.pop();
		return res;
	}
	int peek(){
		return max_heap_.top().second;
	}
private:
	priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> max_heap_;
	int order_=0;	
};

int main(){
	My_Stack st;
	st.push(1);
	st.push(2);
	st.push(3);
	cout<<st.pop();
	cout<<st.pop();
	cout<<st.pop()<<endl;
	My_Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	cout<<q.pop();
	cout<<q.pop();
	cout<<q.pop();
}