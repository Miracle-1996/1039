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
string str; int nb, ns, nc, pb, ps, pc; ll m;

template <class T> inline T &chmin(T &x, const T &y){ return x = min(x, y); }
template <class T> inline T &chmax(T &x, const T &y){ return x = max(x, y); }

ll cal(ll x)
{
	ll cb = max(0ll, x * count(all(str), 'B') - nb);
	ll cs = max(0ll, x * count(all(str), 'S') - ns);
	ll cc = max(0ll, x * count(all(str), 'C') - nc);
	return cb * pb + cs * ps + cc * pc;
}

template <class T> T upper(T l, T r, const T x)
{
	while (l + 1 < r) {
		T mid = l + (r - l) / 2;
		(cal(mid) <= x) ? l = mid : r = mid;
	}
	return l;
}

ll solve(void)
{
	ll x = 1;
	while(cal(x) <= m) x <<= 1;
	return upper(0ll, x, m);
}

signed main(int argc, char** argv)
{
	#ifdef Miracle
		auto start_clock = clock();
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	std::ios::sync_with_stdio(false); cin.tie(nullptr);
	while (cin >> str) {
		cin >> nb >> ns >> nc;
		cin >> pb >> ps >> pc;
		cin >> m;
		cout << solve() << endl;
	}
	#ifdef Miracle
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
}