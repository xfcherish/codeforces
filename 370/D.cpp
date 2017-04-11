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
	if(sum - depth*2*k > (a-b)) return 0;
	if(sum + depth*2*k < (a-b)) return 0;
	if(dp[depth][sum+bias] != -1)
		return dp[depth][sum+bias]; 
	if(depth == 0) {
		if(sum == a-b) return 1;
		else return 0;
	}
	LL ret = 0;
	for(int i = -2*k; i <= 2*k; i++) {
		ret += ways(i)*dfs(depth-1, sum+i);
		ret %= mod;
	}
	dp[depth][sum+bias] = ret;
	return ret;
}

int main()
{
	cin >> a >> b >> k >> t;
	memset(dp,-1,sizeof(dp));
	bias = 2*k*t;
	int ans = 0;
	for(int sum = 1; sum <= a-b + 2*t*k; sum++) {
		ans = ans + dfs(t,sum);
		ans %= mod;
	}		
	cout << ans << endl;
	return 0;
}