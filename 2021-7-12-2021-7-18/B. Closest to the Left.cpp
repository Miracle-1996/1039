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

int search1(int l, int r, int x)
{
	while (l + 1 < r) {
		int mid = l + (r - l) / 2;
		(a[mid] <= x) ? l = mid : r = mid;
	}
	return l;
}

int search2(int l, int r, int x)
{
	while (l < r) {
		int mid = l + (r - l + 1) / 2;
		(a[mid] <= x) ? l = mid : r = mid - 1;
	}
	return (a[l] <= x) ? l : 0;
}

void solve(void)
{
	a[0] = INT_MIN; a[n + 1] = INT_MAX;  
	for (int k = 1; k <= m; ++k) {
		// cout << search1(0, n + 1, b[k]) << endl;
		// cout << search2(1, n, b[k]) << endl;
		cout << upper_bound(a + 1, a + n + 1, b[k]) - (a + 1) << endl;
	} 
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
		for (int k = 1; k <= m; ++k) cin >> b[k];
		solve();
	}
	#ifdef Miracle
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
} 
// type: binary_search

/* tips */
/*
*/

/* editorial */
/*
*/

/* question */
/*
	upper_bound(a + 1, a + n + 1, b[k]) - (a + 1)
*/