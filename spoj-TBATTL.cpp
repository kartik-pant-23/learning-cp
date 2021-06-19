#include<bits/stdc++.h>

#define ll long long
#define f first
#define s second
#define endl "\n"
#define debug(...) cout << " { "<<(#__VA_ARGS__)<<"="<<__VA_ARGS__<< " }" <<endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define MOD 1000000007

using namespace std;

vector<int> prime;
void preCase() {
	vector<bool> isprime(100000);
	rep(i,2,100000) {
		if(isprime[i]) continue;
		prime.pub(i); isprime[true];
		for(int j=2*i; j<100000; j+=i)
			isprime[j] = true;
	}
}

void runCase() {
	preCase();
	unordered_map<int,int> req;
	int n, tmp;
	cin >> n;
	
	vector<int> nums(n);
	rep(i,0,n) cin >> nums[i];
	
	tmp = n;
	for(int num: prime) {
		while(tmp!=0 && tmp%num==0) {
			req[num]++;
			tmp /= num;
		}
		if(tmp==0) break;
	}
	
	int found = 0;
	int s=0,anss=0,e=0,anse=n;
	while(s<=e && e<=n) {
		int flag = 1;
		for(auto it: req) {
			if(it.s > 0) {
				flag = 0;
				break;
			}
		}
		if(flag==1) {
			found = 1;
			if((e-s) < (anse-anss+1)) {
				anse = e-1;
				anss = s;
			}
			if(s<n) {
				int a = nums[s];
				for(auto it: req) {
					while(a!=0 && a%it.f==0) {
						a /= it.f;
						req[it.f]++;
					}
				}
			}
			s++;
		} else {
			if(e<n) {
				int a = nums[e];
				for(auto it: req) {
					while(a!=0 && a%it.f==0) {
						a /= it.f;
						req[it.f]--;
					}
				}
			}
			e++;
		}
	}
	if(found) cout << anss << " " << anse << endl;
	else cout << "-1" << endl;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	runCase();

	return 0;
}
