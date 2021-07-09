#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n, m, q, a[N], b[N], c[N], d[N], s[N];

int cal(int x)
{
	int res = 0;
	memset(s, 0, sizeof(s));
	for (int k = 0; k < q; ++k) {
		(x >> k & 1) ? s[c[k + 1]]++ : s[d[k + 1]]++; 
	}
	for (int k = 1; k <= m; ++k) {
		if (s[a[k]] && s[b[k]]) ++res;
	}
	return res;
}

int solve(void)
{
	int res = 0;
	for (int k = 0; k < (1 << q); ++k) res = max(res, cal(k));
	return res;
}

int main(int argc, char** argv)
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	while (cin >> n >> m) {
		for (int k = 1; k <= m; ++k) cin >> a[k] >> b[k];
		cin >> q;
		for (int k = 1; k <= q; ++k) cin >> c[k] >> d[k];
		cout << solve() << endl;
	}
	return 0;
}