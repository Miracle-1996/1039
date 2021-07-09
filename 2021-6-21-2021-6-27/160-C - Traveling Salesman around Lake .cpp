#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pii = pair<int, int>;

const int N = 2e5 + 10;
int n, m, a[N], d[N];
string str;

int solve(void)
{
	a[n + 1] = m + a[1];
	for (int k = 1; k <= n; ++k) d[k] = a[k + 1] - a[k];
	return m - *max_element(d + 1, d + n + 1);
}

signed main(int argc, char** argv)
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	while (cin >> m >> n) {
		for (int k = 1; k <= n; ++k) cin >> a[k];
		cout << solve() << endl;
	}
	return 0;	
} 