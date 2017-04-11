#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = (1e5)+10;

struct one {
	int p,b;
};
bool cmp(const one & s1, const one & s2) {
	return s1.p < s2.p;
}

int n,dp[maxn],p[maxn];
one a[maxn];

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i].p >> a[i].b;
	memset(dp,0,sizeof(dp));
	sort(a+1,a+1+n,cmp);
	for(int i = 1; i <= n; i++)
		p[i] = a[i].p;
	for(int i = 2; i <= n; i++) {
		int pos = lower_bound(p+1,p+1+n,(p[i]-a[i].b)) - p;
		dp[i] = dp[pos-1] + (i-pos);
	}
	int ans = dp[n];
	for(int i = 1; i <= n; i++) {
		ans = min(ans, dp[i]+(n-i));
	}
	cout << ans << endl;
	return 0;
}