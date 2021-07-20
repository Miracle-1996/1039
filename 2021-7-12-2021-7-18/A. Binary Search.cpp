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

template <class tp> bool lower(tp l, tp r, const tp x)
{
	while (l + 1 < r) {
		tp mid = l + (r - l) / 2;
		(a[mid] >= x) ? r = mid : l = mid;
	}
	return (a[r] == x);
}

template <class tp> bool upper(tp l, tp r, const tp x)
{
	while (l + 1 < r) {
		tp mid = l + (r - l) / 2;
		(a[mid] <= x) ? l = mid : r = mid;
	}
	return (a[l] == x);
}

template <class tp> bool search1(tp l, tp r, const tp x)
{
	while (l < r) {
		tp mid = l + (r - l) / 2;
		(a[mid] >= x) ? r = mid : l = mid + 1;
	}
	return (a[r] == x);
}

template <class tp> bool search2(tp l, tp r, const tp x)
{
	while (l < r) {
		tp mid = l + (r - l + 1) / 2;
		(a[mid] <= x) ? l = mid : r = mid - 1;
	}
	return (a[l] == x);
}

string solve(int x)
{
	/* lower_bound or upper_bound */
	// auto val = lower_bound(a + 1, a + n + 1, x) - a;
	// auto val = upper_bound(a + 1, a + n + 1, x - 1) - a;
	// bool res = (val != n + 1 && a[val] == x) ? true : false;

	/* binary_search */
	// bool res = binary_search(a + 1, a + n + 1, x);

	/* l < r */
	// bool res = search1(1, n, x);
	// bool res = search2(1, n, x);

	/* l + 1 < r */
	a[0] = INT_MIN; a[n + 1] = INT_MAX;
	// bool res = lower(0, n + 1, x);
	bool res = upper(0, n + 1, x);
	return (res) ? "YES" : "NO";
}

signed main(int argc, char** argv)
{
	#ifdef Miracle
		auto start_clock = clock();
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	std::ios::sync_with_stdio(false); cin.tie(nullptr);
	while (cin >> n >> m) {
		for (int k = 1; k <= n; ++k) cin >> a[k];
		for (int k = 1; k <= m; ++k) { int x; cin >> x; cout << solve(x) << endl; }
	}
	#ifdef Miracle
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
}