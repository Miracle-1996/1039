#include <bits/stdc++.h>
#include <atcoder/all>
#define hash _hash
#define endl '\n'
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define cal1(x) __builtin_popcount(x)
using namespace std;
using namespace atcoder;
using ll = int64_t;
using int128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;

const ld pi = M_PI;
const int N = 2e5 + 10;
string str; int a, b; ll n;

template <class T> inline T &chmin(T &x, const T &y){ return x = min(x, y); }
template <class T> inline T &chmax(T &x, const T &y){ return x = max(x, y); }

ll cal(ll x)
{
	int d = to_string(x).size();
	return a * x + 1ll * b * d;
}

ll get(ll x)
{
	ll res = 1;
	while (cal(res) <= x) res <<= 1;
	return min(res, (ll)1e9 + 1);
}

ll searcher(ll l, ll r, ll x)
{
	while (l + 1 < r) {
		ll mid = l + (r - l) / 2;
		(cal(mid) <= x) ? l = mid : r = mid;
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
	while (cin >> a >> b >> n) {
		cout << searcher(0, get(n), n) << endl;
	}
	#ifdef Miracle
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
} 