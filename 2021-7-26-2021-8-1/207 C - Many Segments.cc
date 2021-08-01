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
string str; int n, m, t[N], l[N], r[N];

template <class T> inline T &chmin(T &x, const T &y){ return x = min(x, y); }
template <class T> inline T &chmax(T &x, const T &y){ return x = max(x, y); }

bool cal(int x, int y)
{
	if (l[x] > l[y]) swap(x, y);
	if (r[x] < l[y]) return false;
	if (r[x] == l[y]) {
		bool u = (1 == t[x]) or (3 == t[x]);
		bool v = (1 == t[y]) or (2 == t[y]);
		return (u and v) ? true : false;
	}
	return true;
}

int solve(void)
{
	int res = 0;
	for (int k = 1; k <= n - 1; ++k) {
		for (int i = k + 1; i <= n; ++i) res += cal(k, i);
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
	cout << fixed << setprecision(20);
	std::ios::sync_with_stdio(false); cin.tie(nullptr);
	while (cin >> n) {
		for (int k = 1; k <= n; ++k) cin >> t[k] >> l[k] >> r[k];
		cout << solve() << endl;
	}
	#ifdef Miracle
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
}