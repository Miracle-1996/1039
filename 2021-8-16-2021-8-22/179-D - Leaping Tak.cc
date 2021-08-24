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
string str; int n, m, f[N]; ll d[N];
vector<pii> v;

template <class T> inline T &chmin(T &x, const T &y){ return x = min(x, y); }
template <class T> inline T &chmax(T &x, const T &y){ return x = max(x, y); }

int solve(void)
{
	const int mod = 998244353;
	memset(f, 0, sizeof(f));
	memset(d, 0, sizeof(d));
	d[1] = 1; d[2] = -1;
	for (int k = 1; k <= n; ++k) {
		f[k] = (f[k - 1] + d[k]) % mod;
		for (int i = 0; i < m; ++i) {
			if (k + v[i].first > n) continue;
			int st = k + v[i].first;
			int ed = min(k + v[i].second + 1, n + 1);
			d[st] = (d[st] + f[k]) % mod;
			d[ed] = (d[ed] - f[k] + mod) % mod; 
		}
	}
	v.clear();
	return f[n];
}

signed main(int argc, char** argv)
{
	#ifdef Miracle
		auto start_clock = clock();
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	std::ios::sync_with_stdio(false); cin.tie(nullptr);
	while (cin >> n >> m) {
		for (int k = 1; k <= m; ++k) {
			int x, y; cin >> x >> y; v.push_back({x, y});
		}
		cout << solve() << endl;
	}
	#ifdef Miracle
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
} 