#include <iostream>
#include <vector>
using namespace std;

void fill_surrounded_algorithm_handler(int i, int j, vector<vector<char>>* board, vector<vector<bool>>* visited){
	bool is_surrounded = true;
	int shift[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
	vector<pair<int,int>> q;
	int index=0;
	q.emplace_back(i,j);
	while(index<q.size()){
		pair<int,int> cur = q[index++];
		if(cur.first==0 || cur.first==board->size()-1 || cur.second==0 || cur.second==board->front().size()-1){
			is_surrounded=false;
		}else{
			for(auto m :  shift){
				pair<int,int> next = {i+m[0],j+m[1]};
				if((*board)[next.first][next.second]=='w'&&!(*visited)[next.first][next.second]){
					(*visited)[next.first][next.second]=true;
					q.emplace_back(next);
				}
			}
		}
	}
	if(is_surrounded){
		for(auto m : q){
			(*board)[m.first][m.second]='b';
		}
	}
}

void fill_surrounded_algorithm(vector<vector<char>>* board){
	if(board->empty()){
		return ;
	}
	vector<vector<bool>> visited(board->size(),vector<bool>(board->front().size(),false));
	for(int i=1;i<board->size()-1;i++){
		for(int j=1;j<board->size()-1;j++){
			if(!visited[i][j] && (*board)[i][j]=='w'){
				fill_surrounded_algorithm_handler(i,j,board,&visited);
			}
		}
	}
}

void pint_result(vector<vector<char>>& vec){
	for(auto x: vec){
		for(auto y: x){
			cout<<y<<" ";
		}
		cout<<endl;
	}
}

int main(){
	vector<vector<char>> input(5,vector<char>(5,'b'));
	input[1][1]='w';
	input[1][2]='w';
	input[2][1]='w';
	input[2][2]='w';
	input[0][1]='w';
	pint_result(input);
	cout<<endl;
	fill_surrounded_algorithm(&input);
	pint_result(input);


}