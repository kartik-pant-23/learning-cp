// [CENTROID OF A TREE - A node in the tree removing which forms forest with trees of size 
// less n / 2, where n is the size of original tree]

#include <bits/stdc++.h>
using namespace std;

void calc_size (vector<vector<int>>& graph, vector<int>& subtree_size, int node, int parent = -1) {
    subtree_size[node] = 1;
    for (const int& child: graph[node]) {
        if (child == parent) continue;
        calc_size(graph, subtree_size, child, node);
        subtree_size[node] += subtree_size[child];
    }
}
int main () {
    int n; cin >> n;
    vector<vector<int>> graph(n + 1);
    int x, y;
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    // Select any node as the root and DFS to find size of every sub-tree
    vector<int> subtree_size(n + 1);
    calc_size(graph, subtree_size, 1);

    // Now after finding size of each sub-tree go to the child which satisfies
    // condition of centroid
    int centroid = 1, parent = 0;
    while (true) {
        bool found = true;
        for (const int& child: graph[centroid]) {
            if (child == parent || subtree_size[child] <= n / 2) continue;
            parent = centroid;
            centroid = child;
            found = false;
            break;
        }
        if (found) break;
    }

    cout << "Centroid=" << centroid << '\n';

    return 0;
}
