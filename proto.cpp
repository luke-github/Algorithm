#include <iostream>
#include <vector>
using namespace std;

class My_Queue{
public:
	My_Queue(int capacity) : data_(capacity) {}

	int size(){
		return count_;
	}

	void enqueue(int x){
		if(count_==data_.size()){
			rotate(data_.begin(),data_.begin()+head_,data_.end());
			head_=0;
			tail_=count_;
			data_.resize(data_.size()<<1);
		}
		data_[tail_]=x;
		tail_=(tail_+1)%data_.size();
		count_++;
	}

	int dequeue(){
		if(!count_){
			throw invalid_argument("the queue is empty");
		}
		int result = data_[head_];
		count_--;
		head_=(head_+1)%data_.size();
		return result;

	}
private:
	int head_=0,tail_=0,count_=0;
	vector<int> data_;
};

int main(){
		My_Queue q(5);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;	
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
    cout<<q.size()<<endl;
}