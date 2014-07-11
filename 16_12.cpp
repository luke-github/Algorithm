#include <iostream>
#include <list>
#include <vector>
#include <complex>
#include <numeric>
using namespace std;

int remind_result(vector<int> A, int level){
	int cur = 0;
	for(int i=level;i<A.size();i++){
		cur = cur*10 + A[level];
	}
	return cur;
}

int evaluate_result(list<int> operand_list, list<char>& operator_list){
	auto it = operand_list.begin();
	for(char c : operator_list){
		if(c=='*'){
			int temp = *it;
			it = operand_list.erase(it);
			temp *= *it;
			*it = temp;
		}else{
			it++;
		}
	}
	return accumulate(operand_list.cbegin(),operand_list.cend(),0);
}

bool expression_synthesis_handler(vector<int>& A, int k, list<int>* operand_list, list<char>* operator_list, int cur, int level){
	cur = cur*10 + A[level];
	if(level==A.size()-1){
		operand_list->emplace_back(cur);
		if(evaluate_result(*operand_list,*operator_list)==k){
			auto it = operand_list->cbegin();
			cout<<*it++;
			for(char c : *operator_list){
				cout<<c<<*it++;
			}
			cout<<"="<<k<<endl;
			return true;
		}
		operand_list->pop_back();
	}else{
		// no operator
		if(expression_synthesis_handler(A,k,operand_list,operator_list,cur,level+1)){
			return true;
		}
		// operator +
		operand_list->emplace_back(cur);
		if(k - evaluate_result(*operand_list,*operator_list) <= remind_result(A,level+1)){
			operator_list->emplace_back('+');
			if(expression_synthesis_handler(A,k,operand_list,operator_list,0,level+1)){
				return true;
			}
			operator_list->pop_back();
		}
		operand_list->pop_back();
		// operator *
		operand_list->emplace_back(cur);
		operator_list->emplace_back('*');
		if(expression_synthesis_handler(A,k,operand_list,operator_list,0,level+1)){
			return true;
		}
		operator_list->pop_back();
		operand_list->pop_back();
	}
	return false;
}

void expression_synthesis(vector<int>& A, int k){
	list<int> operand_list;
	list<char> operator_list;
	if(expression_synthesis_handler(A,k,&operand_list,&operator_list,0,0)){
		cout<<"success"<<endl;
	}else{
		cout<<"no solution"<<endl;
	}
}

int main(){
	vector<int> input = {2,2,5};
	expression_synthesis(input,);
}