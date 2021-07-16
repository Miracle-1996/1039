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
string str; int n, m, a[N], st[N], ed[N];

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
	while (l + 1 < r) {
		int mid = l + (r - l) / 2;
		(a[mid] >= x) ? r = mid : l = mid;
	}
	return r;
}

int search3(int l, int r, int x)
{
	while (l < r) {
		int mid = l + (r - l + 1) / 2;
		(a[mid] <= x) ? l = mid : r = mid - 1;
	}
	return (a[l] <= x) ? l : 0;
}


int search4(int l, int r, int x)
{
	while (l < r) {
		int mid = l + (r - l) / 2;
		(a[mid] >= x) ? r = mid : l = mid + 1;
	}
	return (a[r] >= x) ? r : n + 1;
}

void solve(void)
{
	sort(a + 1, a + n + 1);
	a[0] = INT_MIN; a[n + 1] = INT_MAX;
	for (int k = 1; k <= m; ++k) {
		// cout << search1(0, n + 1, ed[k]) - search2(0, n + 1, st[k]) + 1 << endl;
		// cout << search3(1, n, ed[k]) - search4(1, n, st[k]) + 1 << endl;
		int val1 = upper_bound(a + 1, a + n + 1, ed[k]) - (a + 1);
		int val2 = lower_bound(a + 1, a + n + 1, st[k]) - a;
		cout << val1 - val2 + 1 << endl;
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
	while (cin >> n) {
		for (int k = 1; k <= n; ++k) cin >> a[k];
		cin >> m;
		for (int k = 1; k <= m; ++k) cin >> st[k] >> ed[k];
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
	upper_bound(a + 1, a + n + 1, ed[k]) - (a + 1);
	lower_bound(a + 1, a + n + 1, st[k]) - a;
*/