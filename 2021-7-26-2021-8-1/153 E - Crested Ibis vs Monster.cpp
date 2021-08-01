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
string str; int n, m, a[N], b[N];

template <class T> inline T &chmin(T &x, const T &y){ return x = min(x, y); }
template <class T> inline T &chmax(T &x, const T &y){ return x = max(x, y); }

int solve(void)
{
	const int inf = 0x3f3f3f3f;
	vector<vector<int>> f(n + 1, vector<int>(m + 1, inf));
	for (int k = 0; k <= n; ++k) f[k][0] = 0;
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= m; ++i) {
			int x = max(0, i - a[k]);
			f[k][i] = min(f[k][x] + b[k], f[k - 1][i]);
		}
	}
	for (int k = 0; k <= n; ++k) {
		for (int i = 0; i <= m; ++i) cout << f[k][i] << " ";
		cout << endl;
	}
	return f[n][m];
	// vector<int> f(m + 1, inf);
	// f[0] = 0;
	// for (int k = 1; k <= n; ++k) {
	// 	for (int i = 1; i <= m; ++i) {
	// 		int x = max(0, i - a[k]);
	// 		f[i] = min(f[x] + b[k], f[i]);
	// 	}
	// }
	// return f[m];
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
	while (cin >> m >> n) {
		for (int k = 1; k <= n; ++k) cin >> a[k] >> b[k];
		cout << solve() << endl;
	}
	#ifdef Miracle
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
}
/*
f[k][i]:      min(f[k - 1][i],       f[k][i-a[k]] + b[k], f[k][i-2*a[k]] + 2 * b[k], f[k][i-3*a[k]] + 3 * b[k]... + f[k][i-n*a[k]] + n * b[k]);
f[k][i-a[k]]+b[k]             min(f[k - 1][i-a[k] + b[k], f[k][i-2*a[k]] + 2 * b[k], f[k][i-3*a[k]] + 3 * b[k]... + f[k][i-n*a[k]] + n * b[k]);
f[k][i-a[k]]                  min(f[k - 1][i-a[k] + 0     f[k][i-2*a[k]] + 1 * b[k], f[k][i-3*a[k]] + 2 * b[k]... + f[k][i-n*a[k]] + (n - 1) * b[k]);
f[k][i] = min(f[k][i-a[k]] + b[k], f[k][i-a[k]] + b[k]);
*/