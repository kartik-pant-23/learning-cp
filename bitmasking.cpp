// Problem - From the given string STR find two non overlapping subsequences
// that are palindromic, say S1 & S2. Let's define S = |S1| * |S2|.
// Find maximum achievable value of S.
// 1 <= |STR| <= 12

#include <iostream>
using namespace std;

bool isPalindrome(string str, int mask) {
    int p1 = 0, p2 = str.length() - 1;
    while(p1 <= p2) {
	if(((1 << p1) & mask) == 0) p1++;
	else if(((1 << p2) & mask) == 0) p2--;
	else {
	    if(str[p1] != str[p2]) return false;
	    p1++; p2--;
	}
    }
    return true;
}
int main() {
    string str; cin >> str;
    int mask = (1 << (int)str.length()) - 1; 
    int ans = -1;
    for(int i = 1; i < mask; ++i) {
	if(!isPalindrome(str, i)) continue;
	for(int j = i ^ mask; j; j = (j - 1) & (i ^ mask)) {
	    if(!isPalindrome(str, j)) continue;
	    ans = max(ans, __builtin_popcount(i) * __builtin_popcount(j));
	}
    }
    cout << ans << "\n";
    return 0;
}
