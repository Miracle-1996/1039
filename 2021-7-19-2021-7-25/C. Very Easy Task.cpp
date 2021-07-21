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
string str; int n, X, Y;

template <class T> inline T &chmin(T &x, const T &y){ return x = min(x, y); }
template <class T> inline T &chmax(T &x, const T &y){ return x = max(x, y); }

int cal(int x)
{
	int val1 = (x - min(X, Y)) / X;
	int val2 = (x - min(X, Y)) / Y;
	return (x < min(X, Y)) ? 0 : 1 + val1 + val2;
}

template <class tp> tp lower(tp l, tp r, const tp x)
{
	while (l + 1 < r) {
		tp mid = l + (r - l) / 2;
		(cal(mid) >= x) ? r = mid : l = mid;
	}
	return r;
}

int solve(void)
{
	int x = 1;
	while (cal(x) < n) x <<= 1;
	return lower(0, x, n);
}

signed main(int argc, char** argv)
{
	#ifdef Miracle
		auto start_clock = clock();
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	std::ios::sync_with_stdio(false); cin.tie(nullptr);
	while (cin >> n >> X >> Y) {
		cout << solve() << endl;
	}
	#ifdef Miracle
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
}