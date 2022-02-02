// Find the minimum spanning tree in the given graph having 
// n vertices and m edges, with each edge having a weight w.
#include <bits/stdc++.h>
using namespace std;

class dsu {
	private:
		vector<int> _parent, _rank;
	public:
		dsu(int n) {
			_parent.resize(n);
			iota(_parent.begin(), _parent.end(), 0);
			_rank.resize(n, 0);
		}
		int findParent(int node) {
			return node == _parent[node] ? node : _parent[node] = findParent(_parent[node]);
		}
		void unite(int node1, int node2) {
			node1 = findParent(node1);
			node2 = findParent(node2);
			if (node1 != node2) {
				if (_rank[node1] < _rank[node2]) {
					swap(node1, node2);
				}
				_parent[node2] = node1;
				_rank[node1] += _rank[node2];
				_rank[node2] = 0;
			}
		}
};
int main () {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> edges;
	for (int i = 0; i < m; ++i) {
		int x, y, w;
		cin >> x >> y >> w;
		x--, y--;
		edges.push_back({ w, x, y });
	}

	sort(edges.begin(), edges.end());

	dsu ds = dsu(n);
	int mst_weight = 0;
	for (vector<int>& edge: edges) {
		if (ds.findParent(edge[1]) != ds.findParent(edge[2])) {
			mst_weight += edge[0];
			ds.unite(edge[1], edge[2]);
		}
	}

	cout << mst_weight << '\n';

	return 0;
}
