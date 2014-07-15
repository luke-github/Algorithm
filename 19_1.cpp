#include <iostream>
#include <vector>
using namespace std;

struct Point{
	bool operator ==(const Point& that) const{
		return x==that.x && y==that.y;
	}
	int x,y;
};

bool is_ok(Point& m,vector<vector<int>>& maze){
	return m.x>=0 && m.x<maze.size() && m.y>=0 && m.y<maze[m.x].size() && maze[m.x][m.y]==0;
}

bool search_maze_handler(Point& cur, Point& e, vector<vector<int>>* maze, vector<Point>* path){
	if(cur==e){
		return true;
	}

	int shift[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
	for(auto m : shift){
		Point next = {cur.x+m[0],cur.y+m[1]};
		if(is_ok(next,*maze)){
			(*maze)[next.x][next.y] = 1;
			path->emplace_back(next);
			if(search_maze_handler(next,e,maze,path)){
				return true;
			}
			path->pop_back();
		}
	}
	return false;
}


vector<Point> search_maze(vector<vector<int>> maze, Point s, Point e){
	vector<Point> path;
	maze[s.x][s.y]=1;
	path.emplace_back(s);
	if(!search_maze_handler(s,e,&maze,&path)){
		path.pop_back();
	}
	return path;
}

int main(){
	vector<vector<int>> input(10,vector<int>(10,0));
	Point s = {0,0};
	Point e = {9,9};
	input[1][9]=1;
	input[8][9]=1;
	auto res= search_maze(input,s,e);
	for(auto m : res){
		cout<<m.x<<"."<<m.y<<" ";
	}
}