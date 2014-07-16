#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Vertex{
	int d = -1;
	vector<Vertex*> edges;
};

bool BFS_search(Vertex* s){
	queue<Vertex*> q;
	q.emplace(s);
	while(!q.empty()){
		for(Vertex* t : q.front()->edges){
			if(t->d==-1){
				t->d = q.front()->d + 1;
				q.emplace(t);
			}else{
				if(t->d == q.front()->d){
					return false;
				}
			}
		}
		q.pop();
	}
	return true;
}

bool is_feasible(vector<Vertex>* G){
	for(Vertex v : *G){
		if(v.d==-1){
			v.d=0;
			if(!BFS_search(&v)){
				return false;
			}
		}
	}
	return true;
}