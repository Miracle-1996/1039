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
const int M = 2 * N;
string str; int n, m;
int ver[M], nxt[M], head[N], idx;

template <class T> inline T &chmin(T &x, const T &y){ return x = min(x, y); }
template <class T> inline T &chmax(T &x, const T &y){ return x = max(x, y); }

void add(int x, int y) 
{ 
	ver[++idx] = y; nxt[idx] = head[x]; head[x] = idx; 
}

int solve(void)
{
	const int inf = 0x3f3f3f3f;
	const int mod = (int)1e9 + 7;
	vector<int>  d(n + 1, inf);
	vector<int>  f(n + 1,  0);
	queue <int> q; q.push(1); d[1] = 0; f[1] = 1;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int k = head[x]; k; k = nxt[k]) {
			int y = ver[k];
			if (inf != d[y]) assert(d[x] + 1 >= d[y]);
			if (inf == d[y]) {
				d[y] = d[x] + 1; f[y] = f[x]; q.push(y);
			}
			else if (d[x] + 1 == d[y]) f[y] = (f[x] + f[y]) % mod;
		}
	}
	return (inf == d[n]) ? 0 : f[n];
}

signed main(int argc, char** argv)
{
	#ifdef Miracle
		auto start_clock = clock();
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	cout << fixed << setprecision(20);
	std::ios::sync_with_stdio(false); cin.tie(nullptr);
	while (cin >> n >> m) {
		for (int k = 1; k <= m; ++k) {
			int x, y; cin >> x >> y; add(x, y); add(y, x);
		}
		cout << solve() << endl;
		memset(head, 0, sizeof(head)); idx = 0;
	}
	#ifdef Miracle
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
}