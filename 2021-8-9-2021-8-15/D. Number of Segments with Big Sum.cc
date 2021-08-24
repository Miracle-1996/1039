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
string str; int n; ll m, a[N];

template <class T> inline T &chmin(T &x, const T &y){ return x = min(x, y); }
template <class T> inline T &chmax(T &x, const T &y){ return x = max(x, y); }

ll solve1(void)
{
	ll res = 0;
	vector<ll> s(n + 1, 0ll);
	partial_sum(a + 1, a + n + 1, s.begin() + 1);
	for (int l = 0, r = 1; l <= n - 1; ++l) {
		while (r <= n && s[l] + m > s[r]) ++r;
		res += n - r + 1;
	}
	return res;
}

ll solve2(void)
{
	ll res = 0;
	vector<ll> s(n + 1, 0ll);
	partial_sum(a + 1, a + n + 1, s.begin() + 1);
	for (int l = 0, r = 1; r <= n; ++r) {
		while (l <= r - 1 && s[r] - s[l] >= m) ++l;
		res += l;
	}
	return res;
}

ll solution(void)
{
	ll res = 0, sum = 0;
	for (int l = 1, r = 1; r <= n; ++r) {
		sum += a[r];
		if (sum < m) { res += l - 1; continue; }
		while (l <= r && sum - a[l] >= m) { sum -= a[l]; ++l; }
		res += l;
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
	cout << fixed << setprecision(20);
	std::ios::sync_with_stdio(false); cin.tie(nullptr);
	while (cin >> n >> m) {
		for (int k = 1; k <= n; ++k) cin >> a[k];
		// cout << solve1() << endl;
		// cout << solve2() << endl;
		cout << solution() << endl;
	}
	#ifdef Miracle
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
}