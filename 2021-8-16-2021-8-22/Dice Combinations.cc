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
string str; int n, m, a[N];

template <class T> inline T &chmin(T &x, const T &y){ return x = min(x, y); }
template <class T> inline T &chmax(T &x, const T &y){ return x = max(x, y); }

int solve1(void)
{
	const int mod = (int)1e9 + 7;
	vector<int> f(n + 1, 0);
	f[0] = 1;
	for (int k = 0; k <= n - 1; ++k) {
		for (int i = 1; i <= 6; ++i) {
			if (k + i > n) continue;
			f[k + i] = (f[k] + f[k + i]) % mod;
		}
	}
	return f[n];
}

int solve2(void)
{
	const int mod = (int)1e9 + 7;
	vector<int> f(n + 1, 0);
	vector<int> d(n + 1, 0);
	f[0] = 1;
	d[0] = 1; d[1] = -1;
	for (int k = 0; k <= n; ++k) {
		if (k != 0) f[k] = (f[k - 1] + d[k]) % mod; 
		if (k != n) d[k + 1] = (d[k + 1] + f[k]) % mod;
		if (k + 7 <= n) d[k + 7] = ((d[k + 7] - f[k]) % mod + mod) % mod;
	}
	return f[n];
}

int solve3(void)
{
	const int mod = (int)1e9 + 7;
	vector<int> f(n + 1, 0);
	f[0] = 1; f[1] = -1;
	for (int k = 0; k <= n; ++k) {
		if (k != 0) f[k] = (f[k - 1] + f[k]) % mod; 
		if (k != n) f[k + 1] = (f[k + 1] + f[k]) % mod;
		if (k + 7 <= n) f[k + 7] = ((f[k + 7] - f[k]) % mod + mod) % mod;
	}
	return f[n];
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
	while (cin >> n) {
		cout << solve3() << endl;
	}
	#ifdef Miracle
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
}