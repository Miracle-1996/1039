#include <bits/stdc++.h>
#include <atcoder/all>
#define hash _hash
#define endl '\n'
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define cal1(x) __builtin_popcount(x)
using namespace std;
using namespace atcoder;
using ll = int64_t;
using int128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;

const ld pi = M_PI;
const int N = 2e5 + 10;
string str; int n, m, a[N], s[N]; ll f[N][2], f1[2][2], g[N], g1[2];

template <class T> inline T &chmin(T &x, const T &y){ return x = min(x, y); }
template <class T> inline T &chmax(T &x, const T &y){ return x = max(x, y); }

ll solve1(void)
{
	memset(f, 0, sizeof(f));
	f[0][0] = 0; f[0][1] = 1;
	for (int k = 1; k <= n; ++k) {
		ll x = f[k - 1][0] + f[k - 1][1];
		f[k][0] = (s[k]) ? 0 : x;
		f[k][1] = (s[k]) ? x : (1ll << k);
	}
	return f[n][0] + f[n][1];
}

ll solve2(void)
{
	memset(f1, 0, sizeof(f1));
	f1[0][0] = 0; f1[0][1] = 1;
	for (int k = 1; k <= n; ++k) {
		ll x = f1[k - 1 & 1][0] + f1[k - 1 & 1][1];
		f1[k & 1][0] = (s[k]) ? 0 : x;
		f1[k & 1][1] = (s[k]) ? x : (1ll << k);
	}
	return f1[n & 1][0] + f1[n & 1][1];
}

ll solve3(void)
{
	memset(g, 0, sizeof(g));
	g[0] = 1;
	for (int k = 1; k <= n; ++k) {
		g[k] = (s[k]) ? g[k - 1] : g[k - 1] + (1ll << k);
	}
	return g[n];
}

ll solve4(void)
{
	memset(g1, 0, sizeof(g1));
	g1[0] = 1;
	for (int k = 1; k <= n; ++k) {
		g1[k & 1] = (s[k]) ? g1[k - 1 & 1] : g1[k - 1 & 1] + (1ll << k);
	}
	return g1[n & 1];
}

ll solve5(void)
{
	ll res = 1;
	for (int k = 1; k <= n; ++k) {
		res = (s[k]) ? res : res + (1ll << k);
	}
	return res;
}

signed main(int argc, char** argv)
{
	#ifdef Miracle
		auto start_clock = clock();
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	std::ios::sync_with_stdio(false); cin.tie(nullptr);
	while (cin >> n) {
		for (int k = 1; k <= n; ++k) {
			cin >> str;
			s[k] = (str == "AND") ? 1 : 0;
		}
		cout << solve5() << endl;
	}
	#ifdef Miracle
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
} 