#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>

using namespace std;

# define pb push_back
# define mp make_pair

typedef long long LL;
typedef pair<int,int> PII;

const int maxn = 100010;

int n;
int a[maxn], b[maxn],c1[maxn],c2[maxn];
long long dp[maxn],res;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(i > 1)
			b[i-1] = abs(a[i] - a[i-1]);
	}
	for(int i = 1; i < n; i++) {
		if(i % 2 == 1) {
			c1[i] = b[i];
			c2[i] = -b[i];
		}
		else if(i % 2 == 0) {
			c1[i] = -b[i];
			c2[i] = b[i];
		}
	}
	dp[1] = c1[1];
	for(int i = 2; i < n; i++) {
		if(dp[i-1] > 0)
			dp[i] = c1[i] + dp[i-1];
		else dp[i] = c1[i];  
	}
	res = 0;
	for(int i = 1; i < n; i++)
		res = max(res, dp[i]);
	
	memset(dp, 0, sizeof(dp));
	dp[1] = c2[1];
	for(int i = 2; i < n; i++) {
		if(dp[i-1] > 0)
			dp[i] = c2[i] + dp[i-1];
		else dp[i] = c2[i];  
	}
	for(int i = 1; i < n; i++)
		res = max(res, dp[i]);
	cout << res << endl;
	return 0;
}