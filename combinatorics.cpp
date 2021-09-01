#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int cmb2(int n, int r, int p) {
    // Time complexity = O(r * log(n))
    // Not doing mod p, it modular inverse
    if(r > n) return 0;
    if(n - r < r) r = n - r;
    if(r == 0) return 1;
    long long num = 1, den = 1;
    while(r) {
	num *= n;
	den *= r;
	long long gcdval = __gcd(num, den);
	num /= gcdval;
	den /= gcdval;
	n--; r--;
    }
    return num;
}
int cmb1(int n, int r, int p) {
    // Time complexity = O(n*r)
    if(r > n) return 0;
    if(n - r < r) r = n - r;
    if(r == 0) return 1;
    vector<int> nums(r+1);
    nums[0] = 1;
    for(int i = 0; i <= n; ++i) {
	for(int j = min(i,r); j > 0; --j) {
	    nums[j] = (nums[j]%p + nums[j-1]%p) % p;
	}
    }
    return nums[r];
}
int main() {
    int n, r, p;
    cin >> n >> r >> p;
    cout << "CMB1 : " << cmb1(n, r, p) << "\n";
    cout << "CMB2 : " << cmb2(n, r, p) << "\n";
    return 0;
}
