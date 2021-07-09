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
string str; int n, m, a[N];

template <class T> inline T &chmin(T &x, const T &y){ return x = min(x, y); }
template <class T> inline T &chmax(T &x, const T &y){ return x = max(x, y); }

ll solve(void)
{
	int r = count(all(str), 'R');
	int g = count(all(str), 'G');
	int b = count(all(str), 'B');
	ll res = 1ll * r * b * g;
	for (int i = 0; i < sz(str) - 2; ++i) {
		for (int j = i + 1; j < sz(str) - 1; ++j) {
			int k = 2 * j - i;
			if (k >= sz(str)) continue;
			if (str[i] != str[j] and str[i] != str[k] and str[j] != str[k]) --res;
		}
	}
	return res;
}

signed main(int argc, char** argv)
{
	#ifdef Miracle
		auto start_clock = clock();
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	std::ios::sync_with_stdio(false); cin.tie(nullptr);
	while (cin >> n >> str) {
		cout << solve() << endl;
	}
	#ifdef Miracle
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
}
// type: 计数问题 

/* tips */
/*
	乘法原理 + 减法原理
*/

/* editorial */
/*
*/

/* question */
/*
*/