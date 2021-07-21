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
string str; ld n;

template <class T> inline T &chmin(T &x, const T &y){ return x = min(x, y); }
template <class T> inline T &chmax(T &x, const T &y){ return x = max(x, y); }

ld cal(ld x)
{
	return x * x + sqrt(x);
}

template <class tp> tp lower(tp l, tp r, const tp x)
{
	const ld eps = 1e-8;
	while (l + eps < r) {
		tp mid = (l + r) / 2;
		(cal(mid) >= x) ? r = mid : l = mid;
	}
	return r;
}

ld solve(ld l, ld r, const ld x)
{
	for (int k = 1; k <= 100; ++k) {
		ld mid = (l + r) / 2;
		(cal(mid) >= x) ? r = mid : l = mid;
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
	std::ios::sync_with_stdio(false); cin.tie(nullptr);
	cout << fixed << setprecision(20);
	while (cin >> n) {
		cout << lower((ld)0.0, (ld)100000.0, n) << endl;
		// cout << solve((ld)0.0, (ld)100000.0, n) << endl;
	}
	#ifdef Miracle
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
}