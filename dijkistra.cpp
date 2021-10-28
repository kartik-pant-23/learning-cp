#include <bits/stdc++.h>
using namespace std;

using P = pair<int,int>;
using PQ = priority_queue<P,vector<P>,greater<P>>;
void dijkistra(const vector<vector<P>>& graph, vector<int>& ans) {
    PQ pq;
    ans[0] = 0;
    pq.push({ans[0], 0});
    while(!pq.empty()) {
	P p = pq.top(); pq.pop();
	for(const P& info: graph[p.second]) {
	    if(ans[p.second] + info.second < ans[info.first]) {
		ans[info.first] = ans[p.second] + info.second;
		pq.push({ ans[info.first], info.first });
	    }
	}
    }
}
int main() {
    int n, m; cin >> n >> m;
    vector<vector<P>> graph(n);
    int x, y, w;
    for(int i = 0; i < m; ++i) {
	cin >> x >> y >> w;
	graph[x].push_back({y, w});
	graph[y].push_back({x, w});
    }

    // Perform dijkistra's algorithm to find shortest distance from node 0
    vector<int> ans(n, INT_MAX);
    dijkistra(graph, ans);

    for(const int& val: ans) cout << val << " ";
    cout << '\n';
    return 0;
}
