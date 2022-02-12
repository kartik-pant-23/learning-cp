#include <bits/stdc++.h>
using namespace std;

void merge_sort(vector<int>& a, int s, int e) {
	if (s < e) {
		int mid = s + (e - s) / 2;

		// Sorting the two subparts
		merge_sort(a, s, mid);
		merge_sort(a, mid + 1, e);

		{ // Combining these two subparts
			vector<int> L(mid - s + 1), R(e - mid);
			for (int i = s; i <= mid; ++i)
				L[i - s] = a[i];
			for (int i = mid + 1; i <= e; ++i) 
				R[i - mid - 1] = a[i];

			int i = s, ptr1 = 0, ptr2 = 0;
			while (ptr1 < (int)L.size() && ptr2 < (int)R.size()) {
				if (L[ptr1] < R[ptr2]) {
					a[i++] = L[ptr1++];
				} else {
					a[i++] = R[ptr2++];
				}
			}

			while (ptr1 < (int)L.size()) {
				a[i++] = L[ptr1++];
			}
			while (ptr2 < (int)R.size()) {
				a[i++] = R[ptr2++];
			}
		}

	}
}
int main () {
	int n; 
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	merge_sort(a, 0, n - 1);
	for (const int& val: a) {
		cout << val << ' ';
	}
	cout << '\n';

	return 0;
}
