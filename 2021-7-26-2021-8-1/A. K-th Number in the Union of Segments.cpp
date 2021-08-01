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
string str; int n, m; ll a[N], b[N];

template <class T> inline T &chmin(T &x, const T &y){ return x = min(x, y); }
template <class T> inline T &chmax(T &x, const T &y){ return x = max(x, y); }

bool cal(ll x)
{
	ll res = 0;
	for (int k = 1; k <= n; ++k) {
		if (x <= a[k]) continue;
		res += min(b[k], x - 1) - a[k] + 1;
	}
	return res <= m;
}

template <class T> T upper(T l, T r)
{
	while (l + 1 < r) {
		T mid = l + (r - l) / 2;
		(cal(mid)) ? l = mid : r = mid;
	}
	return l;
}

ll solve(void)
{
	ll st = a[1]; 
	for (int k = 2; k <= n; ++k) chmin(st, a[k]); 
	ll ed = 1; 
	while (cal(ed)) ed <<= 1;
	return upper(st, ed + 1);
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
		for (int k = 1; k <= n; ++k) cin >> a[k] >> b[k];
		cout << solve() << endl;
	}
	#ifdef Miracle
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
}