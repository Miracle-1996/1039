/* C - Sum of product of pairs */ 
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const int N = 2e5 + 10;
int n, a[N]; ll sum[N];

int solve(void)
{
	int res = 0;
	const int mod = 1e9 + 7;
	for (int k = 1; k <= n; ++k) sum[k] = sum[k - 1] + a[k];
	for (int k = 1; k <= n - 1; ++k) res = (res + a[k] * ((sum[n] - sum[k]) % mod)) % mod;
	return res; 	
}

signed main(int argc, char** argv)
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	while (cin >> n) {
		for (int k = 1; k <= n; ++k) cin >> a[k];
		cout << solve() << endl;
	} 
	return 0;	
} 
