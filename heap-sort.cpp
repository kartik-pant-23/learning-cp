#include <bits/stdc++.h>
using namespace std;

int heap_size;
void heapify(vector<int>& a, int idx) {
	int root = idx;
	int l_child = idx * 2 + 1, r_child = idx * 2 + 2;
	if (l_child < heap_size && a[l_child] > a[root]) {
		root = l_child;
	}
	if (r_child < heap_size && a[r_child] > a[root]) {
		root = r_child;
	}
	if (root != idx) {
		swap(a[root], a[idx]);
		heapify(a, root);
	}
}
void build_heap(vector<int>& a) {
	int root = heap_size / 2;
	while (root--) {
		heapify(a, root);
	}
}
void heap_sort(vector<int>& a, int s, int e) {
	heap_size = e - s + 1;
	build_heap(a);
	while (heap_size > 1) {
		swap(a[0], a[heap_size - 1]);
		heap_size--;
		heapify(a, 0);
	}
}
int main () {
	int n; 
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	heap_sort(a, 0, n - 1);
	for (const int& val: a) {
		cout << val << ' ';
	}
	cout << '\n';

	return 0;
}
