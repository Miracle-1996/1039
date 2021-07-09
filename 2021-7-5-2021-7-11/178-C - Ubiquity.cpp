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

int ksm(int a, int b, int p)
{
	int res = 1 % p;
	while (b) {
		if (b & 1) res = 1ll * res * a % p;
		a = 1ll * a * a % p; b >>= 1;
	}
	return res;
}

int solve(void)
{
	int res = 0;
	int mod = (int)1e9 + 7;
	int x = ksm(10, n, mod);
	int y = ksm(9, n, mod);
	int z = ksm(8, n, mod);
	res = ((x - 2 * y + z) % mod + mod) % mod;
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
	while (cin >> n) {
		cout << solve() << endl;
	}
	cout << -13 % 3  << " " << 13 % 3 << endl;
	#ifdef Miracle
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
} 