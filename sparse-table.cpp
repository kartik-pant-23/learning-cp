#include<bits/stdc++.h>
using namespace std;

template <typename T, class F=function<T(const T&, const T&)>>
class SparseTable {
	private:
	int n;
	vector<vector<T>> mat;
	F func;
	public:
	SparseTable(const vector<T>& a, const F& f): func(f) {
		n = static_cast<int>(a.size());
		int max_log = 32 - __builtin_clz(n);
		mat.resize(max_log);
		mat[0] = a;
		for(int j = 1; j < max_log; ++j) {
			mat[j].resize(n - (1 << j) + 1);
			for(int i = 0; i <= n - (1 << j); ++i) {
				mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
			}
		}
	}
	T get(int from, int to) const {
		assert(0 <= from && from <= to && to <= n - 1);
		int lg = 32 - __builtin_clz(to - from + 1) - 1;
		return func(mat[lg][from], mat[lg][to - (1<<lg) + 1]);
	}
	void printMat() {
		for(vector<T>& row: mat) {
			for(T& num: row) cout << num << " ";
			cout << "\n";
		}
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; ++i) {
		cin >> nums[i];
	} 
	SparseTable<int> table(nums, [&](const int& a, const int& b) { return (a < b) ?a :b; });
	
	int q;
	cin >> q;
	while(q--) {
		int l, r;
		cin >> l >> r;
		cout << table.get(l,r) << "\n";
	}
	
	return 0;
}
