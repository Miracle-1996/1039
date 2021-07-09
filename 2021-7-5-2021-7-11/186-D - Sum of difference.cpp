/* D - Sum of difference */ 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;
int n; ll a[N], sum[N];

ll solve1(void)
{
	ll res = 0;
	sort(a + 1, a + 1 + n);
	for (int k = 1; k <= n; ++k) sum[k] = sum[k - 1] + a[k];
	for (int k = 1; k <= n - 1; ++k) {
		res += sum[n] - sum[k] - 1ll * (n - k) * a[k];
	}
	return res;
}

ll solve2(void)
{
	ll res = 0;
	sort(a + 1, a + n + 1, greater<int>());
	partial_sum(a + 1, a + n + 1, sum + 1);
	for (int k = 1; k <= n - 1; ++k) {
		res += 1ll * (n - k) * a[k] + sum[k] - sum[n];
	}
	return res;
}

int main(int argc, char** argv)
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	while (cin >> n) {
		for (int k = 1; k <= n; ++k) cin >> a[k];
		cout << solve2() << endl;
	}
	return 0;	
} 
// type: partial-sum + sort()

/* tips */
/*
*/

/* editorial */
/*
*/

/* question */
/*
*/