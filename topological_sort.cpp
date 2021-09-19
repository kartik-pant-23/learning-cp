#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    vector<int> indegree(n);
    for(int i = 0; i < m; ++i) {
	int parent, node; cin >> parent >> node;
	parent--; node--;
	graph[parent].push_back(node);
	indegree[node]++;
    }

    queue<int> nodes;
    for(int i = 0; i < n; ++i)
	if(indegree[i] == 0) nodes.push(i);

    int visited = 0;
    vector<int> sorted;
    while(!nodes.empty()) {
	int parent = nodes.front(); nodes.pop();
	sorted.push_back(parent);
	visited++;
	for(int child: graph[parent]) {
	    indegree[child]--;
	    if(indegree[child] == 0) nodes.push(child);
	}
    }

    if(visited != n) cout << "IMPOSSIBLE\n";
    else {
	for(const int& node: sorted) cout << node << " ";
	cout << "\n";
    }

    return 0;
}
