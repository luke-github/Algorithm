#include <iostream>
#include <vector>
using namespace std;


void paren_handler(int reminder, int left_paren, string* s, vector<string>* res){
	if(reminder==0){
		res->emplace_back(*s);
		return;
	}
	if(left_paren<reminder){
		s->push_back('(');
		paren_handler(reminder-1,left_paren+1,s,res);
		s->pop_back();
	}
	if(left_paren>0){
		s->push_back(')');
		paren_handler(reminder-1,left_paren-1,s,res);
		s->pop_back();
	}
}


vector<string> paren(int n){
	vector<string> res;
	string s;
	paren_handler(n<<1,0,&s,&res);
	return res;
}

int main(){
	auto res = paren(5);
	for(auto x : res){
		cout<<x<<endl;
	}
}