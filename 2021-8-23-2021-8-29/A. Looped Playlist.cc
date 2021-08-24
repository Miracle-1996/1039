#include <bits/stdc++.h>
#define hash _hash
#define endl '\n'
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define cal1(x) __builtin_popcount(x)
using namespace std;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;

const ld pi = acos(-1.0);
const int N = 2e5 + 10;
string str; int n; ll m, a[N];

template <class T> inline T &chmin(T &x, const T &y){ return x = min(x, y); }
template <class T> inline T &chmax(T &x, const T &y){ return x = max(x, y); }

pair<int, ll> solve(void)
{
	vector<ll> s(2 * n + 1, 0ll);
	partial_sum(a + 1, a + 2 * n + 1, s.begin() + 1);
	ll x = (m <= s[n]) ? m : m % s[n];
	if (0 == x) return {1, m / s[n] * n};
	int idx = 1; ll res = INT_MAX;
	for (int l = 0, r = 1; r <= 2 * n; ++r) {
		if (s[r] - s[l] < x) continue;
		while (l <= r - 1 && s[r] - s[l] >= x) ++l;
		if (r - l + 1 < res) idx = l; 
		chmin(res, r - l + 1ll);
	}
	if (idx > n) idx -= n;
	res += (m <= s[n]) ? 0 : m / s[n] * n;
	return {idx, res};
}

signed main(int argc, char** argv)
{
	#ifdef Miracle
		auto start_clock = clock();
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	cout << fixed << setprecision(20);
	std::ios::sync_with_stdio(false); cin.tie(nullptr);
	while (cin >> n >> m) {
		for (int k = 1; k <= n; ++k) cin >> a[k];
		for (int k = 1; k <= n; ++k) a[n + k] = a[k];
		auto res = solve();
		cout << res.first << " " << res.second << endl;
	}
	#ifdef Miracle
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
}