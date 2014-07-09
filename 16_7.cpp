#include <iostream>
#include <vector>
using namespace std;

void paren_solution_handler(int reminder, int left_paren, string* ans, vector<string>* res){
	if(!reminder){
		res->emplace_back(*ans);
		return;
	}
	if(left_paren<reminder){
		ans->push_back('(');
		paren_solution_handler(reminder-1,left_paren+1,ans,res);
		ans->pop_back();
	}
	if(left_paren>0){
		ans->push_back(')');
		paren_solution_handler(reminder-1,left_paren-1,ans,res);
		ans->pop_back();
	}
}

vector<string> paren_solution(int n){
	vector<string> result;
	string ans;
	paren_solution_handler(n<<1,0,&ans,&result);
	return result;
}

int main(){
	auto res = paren_solution(5);
	for(auto x : res){
		cout<<x<<endl;
	}
}