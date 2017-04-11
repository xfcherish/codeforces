#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

#define pb push_back
#define mp make_pair

typedef long long LL;
typedef pair<int,int> PII;

const int mod = (1e9)+7;
const int maxn = (4e5)+500;
LL dp[105][maxn];
int a,b,t,k,bias;

int ways(int diff) {
	return (2*k+1)-abs(diff);
}

LL dfs(int depth, int sum) {
	if(dp[depth][sum+bias] != -1)
		return dp[depth][sum+bias]; 
	if(depth == 0) {
		if(sum == a-b) return 1;
		else return 0;
	}
	LL ret = 0;
	ret = (k+1)*(k+1)*dfs(depth-1, sum+2*k);
	ret %= mod;
	dp[depth][sum+bias] = ret;
	return ret;
}

int main()
{
	cin >> a >> b >> k >> t;
	memset(dp,-1,sizeof(dp));
	bias = 2*k*t;
	int ans = 0;
	ans = ans + dfs(1,sum);
	ans %= mod;	
	cout << ans << endl;
	return 0;
}