#include <bits/stdc++.h>
#include <atcoder/all>
#define hash _hash
#define endl '\n'
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
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
string str; int n, m, a[N], f[N];

template <class T> inline T &chmin(T &x, const T &y){ return x = min(x, y); }
template <class T> inline T &chmax(T &x, const T &y){ return x = max(x, y); }

int solve(void)
{
	for (int k = str.size() - 1; k >= 0; --k) {
		while (str[k] == 'f' && "fox" == str.substr(k, 3)) {
			str.erase(k, 3); 
		}
	}
	return sz(str);
}

int solution(void)
{
	string tp;
	for (auto x : str) {
		if (tp.size() >= 2 && 'f' == tp[tp.size() - 2] && 'o' == tp.back() && 'x' == x) {
			tp.pop_back(); tp.pop_back();
		}
		else tp.push_back(x);
	}	
	return tp.size();
}

signed main(int argc, char** argv)
{
	#ifndef ONLINE_JUDGE
		auto start_clock = clock();
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	std::ios::sync_with_stdio(false); cin.tie(nullptr);
	while (cin >> n >> str) {
		cout << solve() << endl;
	}
	#ifndef ONLINE_JUDGE
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
}
/* tips */
/*
	递推
*/