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

bool cal(ll x)
{
	int cnt = 0; ll sum = 0;
	for (int k = 1; k <= n; ++k) {
		if (sum + a[k] <= x) sum += a[k];
		else if (a[k] > x) return false;
		else { sum = a[k]; ++cnt; }
	}
	return ++cnt <= m;
}

template <class T> T lower(T l, T r, const T x = 0)
{
	while (l + 1 < r) {
		T mid = l + (r - l) / 2;
		(cal(mid)) ? r = mid : l = mid;
	}
	return r;
}

ll solve(void)
{
	ll x = 1;
	while (!cal(x)) x <<= 1;
	return lower(0ll, x, 1ll * m);
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
		cout << solve() << endl;
	}
	#ifdef Miracle
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
}