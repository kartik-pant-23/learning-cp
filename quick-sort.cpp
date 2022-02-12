#include <bits/stdc++.h>
using namespace std;

int quick_part(vector<int>& a, int s, int e) {
	int pivot = e; // Chose last index as pivot, can be a random index as well
	int q = s, ptr = s;
	while (ptr < e) {
		if (a[ptr] <= a[e]) {
			swap(a[ptr], a[q++]);
		}
		ptr++;
	}
	swap(a[e], a[q]);
	return q;
}
void quick_sort(vector<int>& a, int s, int e) {
	if (s < e) {
		int q = quick_part(a, s, e);
		quick_sort(a, s, q - 1);
		quick_sort(a, q + 1, e);
	}
}
int main () {
	int n; 
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	quick_sort(a, 0, n - 1);

	for (const int& val: a) {
		cout << val << ' ';
	}
	cout << '\n';
}
