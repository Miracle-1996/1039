#include <bits/stdc++.h>
#include <atcoder/all>
#define sz(x) ((int)x.size())
using namespace std;
using namespace atcoder;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int N = 3e5 + 10;
string str; int n, a[N], s[N]; ll p[N], sp[N];

ll solve(void)
{
	ll res = 0;
	for (int k = 1; k <= n; ++k) p[k] = a[k] * a[k];
	partial_sum(a + 1, a + n + 1, s + 1);
	partial_sum(p + 1, p + n + 1, sp + 1);
	for (int k = 2; k <= n; ++k) {
		res += (k - 1) * p[k] - 2ll * a[k] * s[k - 1] + sp[k - 1];
	}
	return res;
}

ll solution1(void)
{
	ll res = 0;
	vector<int> v(401, 0);
	for (int k = 1; k <= n; ++k) v[a[k] + 200]++;
	for (int k = 0; k < sz(v) - 1; ++k) {
		for (int i = k + 1; i < sz(v); ++i) {
			ll x = 1ll * v[k] * v[i];
			int val = (k - 200) - (i - 200);
			res += x * val * val;
		}
	} 
	return res;
}

ll solution2(void)
{
	ll res = 0;
	for (int k = 1; k <= n; ++k) p[k] = a[k] * a[k];
	partial_sum(a + 1, a + n + 1, s + 1);
	partial_sum(p + 1, p + n + 1, sp + 1);
	res = n * sp[n] - 1ll * s[n] * s[n];
	return res;
}

signed main(int argc, char** argv)
{
	#ifndef ONLINE_JUDGE
		auto start_clock = clock();
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
	while (cin >> n) {
		for (int k = 1; k <= n; ++k) cin >> a[k];
		cout << solution1() << endl;
	}
	#ifndef ONLINE_JUDGE
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
} 