#include <bits/stdc++.h>
#define hash _hash
#define endl '\n'
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define cal1(x) __builtin_popcount(x)
using namespace std;
using ll = int64_t;
using ld = double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;

const ld pi = acos(-1.0);
const int N = 2e5 + 10;
string str; int n, m, a[N];

template <class T> inline T &chmin(T &x, const T &y){ return x = min(x, y); }
template <class T> inline T &chmax(T &x, const T &y){ return x = max(x, y); }

pii cal(ld x)
{
	vector<ld> v(n + 1);
	for (int k = 1; k <= n; ++k) v[k] = a[k] - x;
	vector<ld> s(n + 1, (ld)0.0);
	partial_sum(v.begin() + 1, v.end(), s.begin() + 1);
	vector<int> minv(n + 1, 0);
	for (int k = 1; k <= n; ++k) {
		minv[k] = (s[minv[k - 1]] <= s[k]) ? minv[k - 1] : k;
	}
	for (int r = m; r <= n; ++r) {
		if (s[minv[r - m]] <= s[r]) return {minv[r - m] + 1, r};
	}
	return {-1, -1};
}

template <class T> pii upper(T l, T r)
{
	pii res;
	for (int k = 1; k <= 100; ++k) {
		T mid = (l + r) / 2;
		auto x = cal(mid);
		if (x.first != -1) { l = mid; res = x; }
		else r = mid;
	}
	return res;
}

pii solve(void)
{
	ld x = 1;
	while (cal(x).first != -1) x *= 2;
	return upper((ld)0.0, x);
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
		// cout << solve() << endl;
		auto res = solve();
		cout << res.first << " " << res.second << endl;
	}
	#ifdef Miracle
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
}