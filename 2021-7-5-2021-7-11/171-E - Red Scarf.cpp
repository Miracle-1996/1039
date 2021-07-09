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

void solve(void)
{
	int x = accumulate(a + 1, a + n + 1, 0, [](int res, int val) { return res ^ val; });
	for (int k = 1; k <= n; ++k) b[k] = x ^ a[k];
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
		for (int k = 1; k <= n; ++k) cin >> a[k];
		solve();
		for (int k = 1; k <= n; ++k) cout << b[k] << " "; cout << endl;
	}
	#ifdef Miracle
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
}
// type: xor

/* tips */
/*
	accumulate + lambda
	accumulate(a + 1, a + n + 1, 0, [](int res, int val) { return res ^ val; });

*/

/* editorial */
/*
*/

/* question */
/*
*/