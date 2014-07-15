#include <iostream>
#include <vector>
using namespace std;

struct point{
	bool operator == (const point& that) const {
		return x==that.x && y==that.y;
	}
	int x,y;
};

bool is_ok(point m, vector<vector<int>>& maze){
	return m.x>=0 && m.x<maze.size() && m.y >=0 && m.y<maze[m.x].size() && maze[m.x][m.y]==0;
}

bool maze_algorithm_handler(point& cur, point end, vector<vector<int>>* maze, vector<point>* path){
	if(cur==end){
		return true;
	}
	int shift[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
	for(auto m : shift){
		point next={cur.x+m[0],cur.y+m[1]};
		if(is_ok(next,*maze)){
			path->emplace_back(next);
			(*maze)[next.x][next.y]=1;
			if(maze_algorithm_handler(next,end,maze,path)){
				return true;
			}
			path->pop_back();
		}
	}
	return false;
}

vector<point> maze_algorithm(vector<vector<int>> maze, point start, point end){
	vector<point> path;
	maze[start.x][start.y]=1;
	path.emplace_back(start);
	if(!maze_algorithm_handler(start,end,&maze,&path)){
		path.pop_back();
	}
	return path;
}

int main(){
	vector<vector<int>> input(10,vector<int>(10,0));
	point s = {0,0};
	point e = {9,9};
	input[1][9]=1;
	input[8][9]=1;
	auto res= maze_algorithm(input,s,e);
	for(auto m : res){
		cout<<m.x<<"."<<m.y<<" ";
	}
}