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

int cmp(ld x, ld y)
{
	const ld eps = 1e-8;
	return (fabs(x - y) <= eps) ? 0 : (x < y) ? -1 : 1;
}

bool cal(ld x)
{
	vector<ld> v1(n, 0);
	vector<ld> v2(n, 0);
	for (int k = 1; k <= n; ++k) {
		v1[k - 1] = a[k] - x * b[k]; 
		v2[k - 1] = a[k] + x * b[k];
	}
	ld l = *max_element(all(v1));
	ld r = *min_element(all(v2));
	return (cmp(r, l) >= 0); 
}

template <class T> T lower(T l, T r, const T x = 0)
{
	const ld eps = 1e-8;
	while (l + eps < r) {
		T mid = l + (r - l) / 2;
		(cal(mid)) ? r = mid : l = mid;
	}
	return r;
}

ld solve(ld l, ld r)
{
	for (int k = 1; k <= 100; ++k) {
		ld mid = l + (r - l) / 2;
		(cal(mid)) ? r = mid : l = mid;
	}
	return r;
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
		for (int k = 1; k <= n; ++k) cin >> a[k] >> b[k];
		// cout << lower(0.0, 1e9) << endl;
		cout << solve(0.0, 1e9) << endl;
	}
	#ifdef Miracle
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
}