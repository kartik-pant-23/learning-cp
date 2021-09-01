#include<bits/stdc++.h>
using namespace std;

int combinatorics(int n, int r, int p) {
    if(n < r || r == 0) return 1;
    vector<int> nums(n+1);
    nums[n/2] = nums[n/2 + 1] = 1;
}
int main() {
    int n, r, p;
    cin >> n >> r >> p;
    cout << combinatorics(n, r, p) << "\n";
    return 0;
}
