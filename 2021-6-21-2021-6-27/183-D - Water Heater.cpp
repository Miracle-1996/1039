/* D - Water Heater */ 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int n, m; ll a[N], d[N];

string solve(void)
{
	const int size = (int)2e5;
	a[0] = d[0];
	for (int k = 1; k <= size; ++k) a[k] = a[k - 1] + d[k];
	ll x = *max_element(a, a + size + 1);
	return (x <= m) ? "Yes" : "No";
}

int main(int argc, char** argv)
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	while (cin >> n >> m) { 
		memset(a, 0, sizeof(a));
		memset(d, 0, sizeof(d));
		for (int k = 1; k <= n; ++k) {
			int l, r, c; cin >> l >> r >> c;
			d[l] += c; d[r] -= c;
		}
		cout << solve() << endl;
	}
	return 0;	
} 
