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
string str; int n, m, t[N], y[N], z[N];

template <class T> inline T &chmin(T &x, const T &y){ return x = min(x, y); }
template <class T> inline T &chmax(T &x, const T &y){ return x = max(x, y); }

int get(int x, int k)
{
	int val = t[k] * z[k] + y[k];
	return x / val * z[k] + min(x % val / t[k], z[k]);
}

bool cal(int x)
{
	int sum = 0;
	for (int k = 1; k <= n; ++k) sum += get(x, k);
	return sum >= m;
}

template <class T> T lower(T l, T r)
{
	while (l + 1 < r) {
		T mid = l + (r - l) / 2;
		(cal(mid)) ? r = mid : l = mid;
	}
	return r;
}

void solve(void)
{
	int x = 1;
	while (!cal(x)) x <<= 1;
	int res = lower(-1, x);
	cout << res << endl;
	int sum = 0;
	vector<int> v(n + 1, 0);
	for (int k = 1; k <= n; ++k) {
		int tp = get(res, k);
		if (sum < m) v[k] = min(tp, m - sum);
		sum += v[k];
	}
	for (int k = 1; k <= n; ++k) cout << v[k] << " "; cout << endl;
}

signed main(int argc, char** argv)
{
	#ifdef Miracle
		auto start_clock = clock();
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	std::ios::sync_with_stdio(false); cin.tie(nullptr);
	while (cin >> m >> n) {
		for (int k = 1; k <= n; ++k) cin >> t[k] >> z[k] >> y[k];
		solve();
	}
	#ifdef Miracle
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
}