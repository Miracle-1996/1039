#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string str;

int cal(int x, int size)
{
	string tp;
	for (int k = 0; k < size; ++k) {
		if (x >> k & 1) tp += str[k];
	}
	ll val = stol(tp);
	return (0 == val % 3) ? tp.size() : 0;
}

int solve(void)
{
	int res = 0;
	int size = str.size();
	for (int k = 1; k < (1 << size); ++k) {
		res = max(res, cal(k, size));
	}
	return (0 == res) ? -1 : size - res;
}

int main(int argc, char** argv)
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	while (cin >> str) {
		cout << solve() << endl;
	}
	return 0;
}
