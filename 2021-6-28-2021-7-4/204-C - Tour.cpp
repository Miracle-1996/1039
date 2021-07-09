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
const int N = 2010;
const int M = 2010;
string str; int n, m, a[N];
int ver[M], edge[M], nxt[M], head[N], idx; int d[N];
bool in[N];

template <class T> inline T &chmin(T &x, const T &y){ return x = min(x, y); }
template <class T> inline T &chmax(T &x, const T &y){ return x = max(x, y); }

void add(int x, int y, int z) 
{ 
	ver[++idx] = y; edge[idx] = z; nxt[idx] = head[x]; head[x] = idx; 
}

void dfs(int st, int x, int& res)
{
	in[x] = true; ++res;
	for (int k = head[x]; k; k = nxt[k]) {
		int y = ver[k];
		if (in[y]) continue;
		dfs(st, y, res);
	}
}

int solution1(void)
{
	int res = 0;
	for (int k = 1; k <= n; ++k) {
		memset(in, false, sizeof(in));
		dfs(k, k, res);
	}	
	return res;
}

void bfs(int st, int x, int& res)
{
	queue<int> q; q.push(x); in[x] = true; 
	while (q.size()) {
		int top = q.front(); q.pop();
		++res;
		for (int k = head[top]; k; k = nxt[k]) {
			int y = ver[k];
			if (in[y]) continue;
			q.push(y); in[y] = true;
		}
	}
}

int solution2(void)
{
	int res = 0;
	for (int k = 1; k <= n; ++k) {
		memset(in, false, sizeof(in));
		bfs(k, k, res);
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
		for (int k = 1; k <= m; ++k) {
			int x, y; cin >> x >> y;
			add(x, y, 1);
		}
		cout << solution1() << endl;
		memset(head, 0, sizeof(head)); idx = 0;
	}
	#ifdef Miracle
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
} 