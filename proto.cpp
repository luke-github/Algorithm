#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node{
	int value;
	vector<Node*> edges;
};

Node* clone_graph(Node* G){
	if(!G){
		return nullptr;
	}
	unordered_map<Node*,Node*> hash;
	queue<Node*> q;
	hash.emplace(G,new Node({G->value}));
	q.emplace(G);
	while(!q.empty()){
		Node* cur = q.front();
		q.pop();
		for(auto x : cur->edges){
			if(hash.find(x)==hash.end()){
				hash.emplace(x,new Node({x->value}));
				q.emplace(x);
			}
			hash[cur]->edges.emplace_back(hash[x]);
		}
	}
	return hash[G];
}