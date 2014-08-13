#include <queue>
#include <deque>
#include <iostream>
using namespace std;

template<class T>
class max_queue{
public:
	void enqueue(T x){
		Q_.emplace(x);
		while(!D_.empty()&&D_.back()<x){
			D_.pop_back();
		}
		D_.emplace_back(x);
	}

	T dequeue(){
		if(!Q_.empty()){				
			T res = Q_.front();
			if(res==D_.front()){
				D_.pop_front();
			}
			Q_.pop();
			return res;
		}else{
			throw invalid_argument("error");
		}
	}

	T max(){
		if(!D_.empty()){
			return D_.front();
		}else{
			throw invalid_argument("error");
		}
	}
private:
	queue<T> Q_;
	deque<T> D_;
};

int main(){
	max_queue<int> q1;
	q1.enqueue(1);
	q1.enqueue(2);
	q1.enqueue(3);
	q1.enqueue(4);
	cout<<q1.max()<<endl;
	q1.dequeue();
	cout<<q1.max()<<endl;
	q1.enqueue(5);
	cout<<q1.max()<<endl;

}