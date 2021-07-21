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
string t, p; int n, m, a[N];

template <class T> inline T &chmin(T &x, const T &y){ return x = min(x, y); }
template <class T> inline T &chmax(T &x, const T &y){ return x = max(x, y); }

bool cal(int x)
{
	vector<bool> v(sz(t), true);
	for (int k = 1; k <= x; ++k) v[a[k] - 1] = false;
	string str;
	for (int k = 0; k < sz(t); ++k)  if (v[k]) str += t[k];
	int l = 0, r = 0;
	while (l < sz(str) && r < sz(p)) if (str[l++] == p[r]) ++r;
	return (r == sz(p));
}

template <class T> T upper(T l, T r)
{
	while (l + 1 < r) {
		T mid = l + (r - l) / 2;
		(cal(mid)) ? l = mid : r = mid;
	}
	return l;
}

signed main(int argc, char** argv)
{
	#ifdef Miracle
		auto start_clock = clock();
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	std::ios::sync_with_stdio(false); cin.tie(nullptr);
	while (cin >> t >> p) {
		for (int k = 1; k <= sz(t); ++k) cin >> a[k];
		cout << upper(0, sz(t)) << endl; 
	}
	#ifdef Miracle
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
}