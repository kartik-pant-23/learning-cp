// Finding fibonacci using matrix-exponentiation
// in O(logn) time
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
void multiply(int a[2][2], int b[2][2]) {
    int mul[2][2];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            mul[i][j] = 0;
            for (int k = 0; k < 2; ++k) {
                mul[i][j] += ((long long) a[i][k] * b[k][j]) % MOD;
                mul[i][j] %= MOD;
            }
        }
    }
    memcpy(a, mul, 4 * sizeof(int));
}
int find_fibonacci(int n, int m) {
    int a[2][2]= { {0,1}, {1,1} };
    int ans[2][2] = { {1,0}, {0,1} };
    while (n) {
        if (n & 1) {
            multiply(ans, a);
        }
        multiply(a, a);
        n >>= 1;
    }
    return ans[0][0];
}
int main () {
    int n; cin >> n;
    assert(n > 0);
    int ans = find_fibonacci(n, MOD);
    cout << ans << '\n';
    return 0;
}
