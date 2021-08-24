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

bool cal(ld x)
{
	vector<ld> v(n, 0);
	for (int k = 1; k <= n; ++k) v[k - 1] = a[k] - b[k] * x;
	nth_element(v.begin(), v.begin() + m, v.end(), greater<ld>{});
	ld sum = accumulate(v.begin(), v.begin() + m, (ld)0.0);
	return sum >= (ld)0.0;
}

template <class T> T upper(T l, T r)
{
	for (int k = 1; k <= 100; ++k) {
		T mid = (l + r) / 2;
		(cal(mid)) ? l = mid : r = mid;
	}
	return l;
}

ld solve(void)
{
	ld x = 1;
	while (cal(x)) x *= 2;
	return upper((ld)0.0, x);
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
		for (int k = 1; k <= n; ++k) cin >> a[k] >> b[k];
		cout << solve() << endl;
	}
	#ifdef Miracle
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
}