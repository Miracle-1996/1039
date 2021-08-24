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
const int lgN = 20;
string str; int n; ll m, a[N];
int lg2[N]; ll f[N][lgN], g[N][lgN];

template <class T> inline T &chmin(T &x, const T &y){ return x = min(x, y); }
template <class T> inline T &chmax(T &x, const T &y){ return x = max(x, y); }

void init(void)
{
	memset(lg2, 0, sizeof(lg2));
	lg2[1] = 0;
	for (int k = 2; k <= n; ++k) lg2[k] = lg2[k >> 1] + 1;
	memset(f,    0, sizeof(f));
	memset(g, 0x3f, sizeof(g));
	for (int k = 1; k <= n; ++k) f[k][0] = a[k];
	for (int k = 1; k <= n; ++k) g[k][0] = a[k];
	for (int len = 1; len <= lg2[n]; ++len) {
		for (int k = 1; k + (1 << len) - 1 <= n; ++k) {
			f[k][len] = max(f[k][len - 1], f[k + (1 << (len - 1))][len - 1]);
			g[k][len] = min(g[k][len - 1], g[k + (1 << (len - 1))][len - 1]);
		} 
	}
}

ll get_max(int l, int r)
{
	int x = lg2[r - l + 1];
	return max(f[l][x], f[r - (1 << x) + 1][x]);
}

ll get_min(int l, int r)
{
	int x = lg2[r - l + 1];
	return min(g[l][x], g[r - (1 << x) + 1][x]);
}

ll query(int l, int r)
{
	ll maxv = get_max(l, r);
	ll minv = get_min(l, r);
	return maxv - minv;
}

ll solve(void)
{
	init();
	ll res = 0;
	for (int l = 1, r = 1; r <= n; ++r) {
		while (l <= r && query(l, r) > m) ++l;
		res += r - l + 1;
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