#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;

ll cal(int x)
{
	string val = to_string(x) + to_string(x);
	return stoll(val);
}

int solve1(void)
{
	int res = 0;
	int st = 1, ed = 999999;
	for (int k = st; k <= ed; ++k) {
		if (cal(k) <= n) ++res;
	}
	return res;
}

int solve2(void)
{
	int res = 0;
	while (cal(res) <= n) ++res;
	return res - 1;
}

int solve3(void)
{
	int l = 0, r = 1000000;
	while (l + 1 < r) {
        int mid = l + (r - l) / 2;
        (cal(mid) <= n) ? l = mid : r = mid;
    }
    return l;
}

int ksm(int a, int b)
{
    int res = 1;
    while (b) {
        if (b & 1) res = (ll)res * a;
        a = (ll)a * a; b >>= 1;
    }
    return res;
}

int solve4(void)
{
	int size = to_string(n).size();
	if (size & 1) return ksm(10, (size - 1) / 2) - 1;
	auto val1 = stoi(to_string(n).substr(0, size / 2));
	auto val2 = stoi(to_string(n).substr(size / 2));
	return (val1 <= val2) ? val1 : val1 - 1;
}

int main(int argc, char** argv)
{
	#ifdef Miracle
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	while (cin >> n) {
		// cout << solve1() << endl;
		// cout << solve2() << endl;
		cout << solve3() << endl;
		// cout << solve4() << endl;
	}
	return 0;
}