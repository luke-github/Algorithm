#include <iostream>
#include <stack>
using namespace std;


class My_Queue{
public:
	void enqueue(int x){
		stack_a_.emplace(x);
	}
	int dequeue(){
		if(stack_b_.empty()){
			while(!stack_a_.empty()){
				stack_b_.emplace(stack_a_.top());
				stack_a_.pop();
			}
		}
		if(!stack_b_.empty()){
			int result = stack_b_.top();
			stack_b_.pop();
			return result;
		}else{
			throw invalid_argument("empty queue");
		}
	}
private:
	stack<int> stack_a_,stack_b_;
};
int main(){
		My_Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	cout<<q.dequeue();
	cout<<q.dequeue();
	cout<<q.dequeue();
	cout<<q.dequeue();
	cout<<q.dequeue();
	// cout<<q.dequeue();
}