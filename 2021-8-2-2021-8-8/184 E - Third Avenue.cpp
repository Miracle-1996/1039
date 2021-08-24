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
string str; int n, m, a[N]; char s[N][N];

template <class T> inline T &chmin(T &x, const T &y){ return x = min(x, y); }
template <class T> inline T &chmax(T &x, const T &y){ return x = max(x, y); }

int bfs(pii st, pii ed, vector<vector<pii>>& v)
{
	#define x first 
	#define y second
	vector<int> dx = {-1, 0, 1, 0};
	vector<int> dy = {0, -1, 0, 1};
	vector<bool> vi(26, false);
	vector<vector<int>> d(n + 1, vector<int>(m + 1, -1));
	queue<pii> q; q.push(st); d[st.x][st.y] = 0;
	while (!q.empty()) {
		auto top = q.front(); q.pop();
		if (top.x == ed.x && top.y == ed.y) break;
		for (int k = 0; k < 4; ++k) {
			int X = top.x + dx[k];
			int Y = top.y + dy[k];
			if (X < 1 || X > n) continue;
			if (Y < 1 || Y > m) continue;
			if ('#' == s[X][Y]) continue;
			if (-1 != d[X][Y]) continue;
			q.push({X, Y});
			d[X][Y] = d[top.x][top.y] + 1;
 		}
 		int idx = s[top.x][top.y] - 'a';
 		if (islower(s[top.x][top.y]) && !vi[idx]) {
 			vi[idx] = true;
			for (auto val : v[idx]) {
				if (-1 != d[val.x][val.y]) continue;
				q.push(val);
				d[val.x][val.y] = d[top.x][top.y] + 1;
			}
		}
	}
	return d[ed.x][ed.y];
}

int solve(void)
{
	pii st, ed;
	vector<vector<pii>> v(26);
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= m; ++i) {
			if ('S' == s[k][i]) st = {k, i};
			if ('G' == s[k][i]) ed = {k, i};
			if (islower(s[k][i])) v[s[k][i] - 'a'].push_back({k, i});
		}
	}
	return bfs(st, ed, v);
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
		for (int k = 1; k <= n; ++k) cin >> s[k] + 1;
		cout << solve() << endl;
	}
	#ifdef Miracle
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
}