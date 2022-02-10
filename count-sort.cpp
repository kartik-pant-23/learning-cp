// Counting Sort 
// This sorting is useful when the range of elements is somewhat closer to the 
// number of elements. Like in case of long strings of let's say lowercase letters
// because the range would be of 26 only.
//
// time compl.	- O(n + k)
// space compl.	- O(n + k)
// [n - number of elements & k - range of input]
//
// Ques - Sort the given array of numbers using counting sort.
#include<bits/stdc++.h>
using namespace std;

int main () {
	int n; cin >> n;
	vector<int> nums(n);

	// storing max and min element in the array to know the range
	int mx_elem = INT_MIN, mn_elem = INT_MAX;
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
		mx_elem = max(mx_elem, nums[i]);
		mn_elem = min(mn_elem, nums[i]);
	}

	vector<int> count(mx_elem - mn_elem + 1); // stores frequency of each element
	for (int i = 0; i < n; ++i) {
		count[nums[i] - mn_elem]++;
	}

	// storing the sorted array in the 
	int ptr = 0;
	vector<int> ans(n);
	for (int i = 0; i < (int)count.size(); ++i) {
		while (count[i]) {
			ans[ptr++] = i + mn_elem;
			--count[i];
		}
	}

	// printing the sorted array
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;
}
