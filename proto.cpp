#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct GraphVertex{
	int d = -1;
	vector<GraphVertex*> edges;
};

bool BSF_search(GraphVertex* s){
	queue<GraphVertex*> q;
	q.emplace(s);
	while(!q.empty()){
		for(GraphVertex* m : q.front()->edges){
			if(m->d==-1){
				m->d = q.front()->d +1;
				q.emplace(m);
			}else{
				if(m->d==q.front()->d){
					return false;
				}
			}
		}
		q.pop();
	}
	return true;
}
 
 
bool is_feasible(vector<GraphVertex>* G){
	for(GraphVertex s : *G){
		if(s.d==-1){
			s.d=0;
			if(!BSF_search(&s)){
				return false;
			}
		}
	}
	return true;
} 