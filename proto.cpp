#include <stack>
#include <vector>
#include <iostream>
#include <array>
using namespace std;
void hanoi_handler(int n,array<stack<int>,3>& pegs,int from,int to,int use);

void hanoi(int n){
	array<stack<int>,3> pegs;
	for(int i=n;i>0;i--){
		pegs[0].push(i);
	}
	hanoi_handler(n,pegs,0,1,2);
}

void hanoi_handler(int n,array<stack<int>,3>& pegs,int from,int to,int use){
	if(n>0){
		hanoi_handler(n-1,pegs,from,use,to);
		pegs[to].push(pegs[from].top());
		pegs[from].pop();
		cout<<"move from "<<from<<" to "<<to<<endl;
		hanoi_handler(n-1,pegs,use,to,from);
	}
}

int main(){
	hanoi(10);
}