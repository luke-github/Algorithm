#include <iostream>
#include <memory>
using namespace std;

class BST_Node{
public:
	bool isLocked(){
		return lock_;
	}
	void lock(){
		if(!lock_&&numoflocks_==0){
			shared_ptr<BST_Node> ptr = parent_;
			while(ptr){
				if(ptr->lock_){
					return;
				}
				ptr=ptr->parent_;
			}
			lock_=true;
			ptr=parent_;
			while(ptr){
				ptr->numoflocks_++;
				ptr=ptr->parent_;
			}
		}
	}
	void unLock(){
		if(lock_){
			shared_ptr<BST_Node> ptr = parent_;
			while(ptr){
				ptr->numoflocks_--;
				ptr=ptr->parent_;
			}
			lock_=false;
		}
	}

private:
	shared_ptr<BST_Node> left_,right_,parent_;
	bool lock_;
	int numoflocks_;
};
int main(){
	
}