/* C - A x B + C */ 
#include <bits/stdc++.h>
using namespace std;

int n;

int solve1(void)
{
	int res = 0;
	int l = 1, r = n - 1;
	for (; l <= n - 1; ++l) {
		while (r && l * r > n - 1) --r;
		res += r;
	}
	return res;
}

int solve2(void)
{
	int res = 0;
	for (int k = 1; k <= n - 1; ++k) res += (n - 1) / k;
	return res;
}

signed main(int argc, char** argv)
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	while (cin >> n) {
		cout << solve1() << endl;
	}
	return 0;	
} 
