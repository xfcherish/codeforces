#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int maxn = (1e5)+10;

long long ans;
int main()
{
	int k2,k3,k5,k6;
	cin >> k2 >> k3 >> k5 >> k6;
	ans = 0;
	int m = min(k2,k5);
	m = min(m,k6);
	ans = ans + m*256;
	k2 = k2 - m;
	ans = ans + min(k2,k3)*32;
	cout << ans << endl;
	return 0;
}