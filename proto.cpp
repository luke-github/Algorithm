#include <unordered_map>
#include <unordered_set>
#include <map>
#include <iostream>
using namespace std;

class CreditClient{
public:
	bool insert(string name, int value){
		if(credits_.emplace(name,value - offset_).second){
			inverse_credits_[value - offset_].emplace(name);
			return true;
		}
		return false;
	}
	bool remove(string name){
		auto credit_it = credits_.find(name);
		if(credit_it!=credits_.end()){
			inverse_credits_[credit_it->second].erase(name);
			credits_.erase(credit_it);
			return true;
		}
		return false;
	}
	int lookup(string name){
		auto it = credits_.find(name);
		return it == credits_.end() ? -1 : it->second+offset_;
	}
	void addAll(int c){
		offset_+=c;
	}
	string max_value(){
		auto it = inverse_credits_.crbegin();
		return it == inverse_credits_.crend() || it->second.empty() ? "" : *it->second.cbegin();
	}
private:
	unordered_map<string,int> credits_;
	map<int,unordered_set<string>> inverse_credits_;
	int offset_=0;
};