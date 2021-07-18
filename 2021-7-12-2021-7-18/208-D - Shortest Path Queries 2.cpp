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
const int N = 500;
string str; int n, m, a[N][N], f[N][N][N];

template <class T> inline T &chmin(T &x, const T &y){ return x = min(x, y); }
template <class T> inline T &chmax(T &x, const T &y){ return x = max(x, y); }

ll solve(void)
{
	const int inf = 0x3f3f3f3f;
	memset(f, 0x3f, sizeof(f));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) f[0][i][j] = a[i][j];
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				f[k][i][j] = f[k - 1][i][j];
				if ((inf == f[k - 1][i][k]) || (inf == f[k - 1][k][j])) continue;
				chmin(f[k][i][j], f[k - 1][i][k] + f[k - 1][k][j]);
			}
		}
	}
	ll res = 0;
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (inf != f[k][i][j]) res += f[k][i][j];
			}
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
	while (cin >> n >> m) {
		memset(a, 0x3f, sizeof(a));
		for (int k = 1; k <= n; ++k) a[k][k] = 0;
		for (int k = 1; k <= m; ++k) {
			int x, y, z; cin >> x >> y >> z; a[x][y] = z;
		}
		cout << solve() << endl;
	}
	#ifdef Miracle
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
} 
// type:  dp-the essence of the Floyd–Warshall algorithm

/* tips */
/*
	f[k][i][j]:所有起点为i，终点为j，只经过前k个节点的路径中的最小值
	初值:
	f[0][i][j] = a[i][j];
	递推关系:
	f[k][i][j] = min(f[k - 1][i][j], f[k - 1][i][k] + f[k - 1][k][j]);
*/

/* editorial */
/*
*/

/* question */
/*
*/