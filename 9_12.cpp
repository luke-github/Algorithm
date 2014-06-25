#include <iostream>
#include <stack>
using namespace std;

class My_Queue{
public:
	void enqueue(int x){
		sta_.emplace(x);
	}

	int dequeue(){
		if(stb_.empty()){
			while(!sta_.empty()){
				stb_.emplace(sta_.top());
				sta_.pop();
			}
		}
		if(!stb_.empty()){
			int result = stb_.top();
			stb_.pop();
			return result;
		}else{
			throw invalid_argument("none element in queue");
		}
	}
private:
	stack<int> sta_,stb_;
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
}