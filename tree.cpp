#include<bits/stdc++.h>
using namespace std;

class Graph{
	private:
		int vertex;
		vector<vector<int>> edges;
	public:
		Graph(int mvertex) {
			vertex = mvertex;
			edges.resize(vertex);
		}
		void insert(int u, int v);
		void BFS(int root);
		void DFS(int root);
		void print();
};

void Graph::insert(int u, int v) {
	edges[u].push_back(v);
}
void Graph::BFS(int root) {
	vector<bool> visited(vertex,false);
	visited[root] = true;
	list<int> queue;
	
	queue.push_back(root);
	while(!queue.empty()) {
		int s=queue.front();
		cout << "  " << s;
		queue.pop_front();
		
		for(int dest : edges[s]) 
			if(!visited[dest]) {
				visited[dest]=true;
				queue.push_back(dest);
			}
	}
}
void Graph::DFS(int root) {
	vector<bool> visited(vertex, false);
	visited[root] = true;
	list<int> queue;
	queue.push_back(root);
	cout << "  " << root;
	
	int flag=1, s;
	while(!queue.empty()){
		s = queue.back(); flag=1;
		for(int edge : edges[s]) {
			if(!visited[edge]) {
				visited[edge]=true; flag=0;
				cout << "  " << edge;
				queue.push_back(edge);
				break;
			}
		}
		if(flag) queue.pop_back();
	}
}
	
void Graph::print() {
	for(int i=0; i<vertex; i++) {
		cout << i << " -> ";
		for(int node : edges[i]) {
			cout << node << " ";
		}
		cout << "\n";
	}
}

int main() {
	Graph graph = Graph(5);
	graph.insert(0,1);
	graph.insert(0,2);
	graph.insert(1,3);
	graph.insert(1,4);
	graph.insert(2,4);
	
	cout << "=====GRAPH=====\n";
	graph.print();
	
	cout << "BFS :";
	graph.BFS(0);
	
	cout << "\n";
	
	cout << "DFS :";
	graph.DFS(0);
}
