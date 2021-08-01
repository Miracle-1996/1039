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
string str; int n, m, a[N];

template <class T> inline T &chmin(T &x, const T &y){ return x = min(x, y); }
template <class T> inline T &chmax(T &x, const T &y){ return x = max(x, y); }

int solve(void)
{
	const int mod = (int)1e9 + 7;
	string tp = "chokudai"; 
	n = sz(str); m = sz(tp);
	vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
	for (int k = 0; k <= n; ++k) f[k][0] = 1;
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= min(k, m); ++i) {
			f[k][i] = (f[k - 1][i] + (str[k - 1] == tp[i - 1]) * f[k - 1][i - 1]) % mod;
		}
	}
	return f[n][m];
	// vector<int> f(m + 1, 0);
	// f[0] = 1;
	// for (int k = 1; k <= n; ++k) {
	// 	for (int i = min(k, m); i >= 1; --i) {
	// 		f[i] = (f[i] + (str[k - 1] == tp[i - 1]) * f[i - 1]) % mod;
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
	while (cin >> str) {
		cout << solve() << endl;
	}
	#ifdef Miracle
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
}