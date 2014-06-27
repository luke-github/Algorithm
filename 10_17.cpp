#include <iostream>
#include <memory>
using namespace std;

class BST_Node{
public:
	
	bool is_lock(){
		return lock_;
	}

	void lock(){
		if(numoflocks_==0&&!lock_){
			shared_ptr<BST_Node> ptr = parent_;
			while(ptr){
				if(ptr->lock_){
					return;
				}
				ptr=ptr->parent_;
			}
			lock_ = true;
			ptr = parent_;
			while(ptr){
				++ptr->numoflocks_;
				ptr=ptr->parent_;
			}
		}
	}

	void un_lock(){
		if(lock_){
			lock_=false;
			shared_ptr<BST_Node> ptr=parent_;
			while(ptr){
				--ptr->numoflocks_;
				ptr=ptr->parent_;
			}
		}
	}

private:
	shared_ptr<BST_Node> left_,right_,parent_;
	bool lock_;
	int numoflocks_;
};

int main(){
}