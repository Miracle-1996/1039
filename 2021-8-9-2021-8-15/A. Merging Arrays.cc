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
string str; int n, m, a[N], b[N];

template <class T> inline T &chmin(T &x, const T &y){ return x = min(x, y); }
template <class T> inline T &chmax(T &x, const T &y){ return x = max(x, y); }

void solve(void)
{
	vector<int> f(n + m, 0);
	int l = 1, r = 1, idx = 0;
	while (l <= n && r <= m) {
		f[idx++] = (a[l] < b[r]) ? a[l++] : b[r++];
	}
	while (l <= n) f[idx++] = a[l++];
	while (r <= m) f[idx++] = b[r++];
	for (auto x : f) cout << x << " "; cout << endl;
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
		for (int k = 1; k <= m; ++k) cin >> b[k];
		solve();
	}
	#ifdef Miracle
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
}