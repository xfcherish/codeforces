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

const int maxn = (1e6)+10;
char s[maxn];
int nxtD[maxn],preU[maxn],n;
LL dp[maxn];

LL dfs(int num) {
	if(dp[num] != -1) return dp[num];
	if(s[num] == 'U') {
		if(nxtD[num] == -1) 
			dp[num] = n-num+1;
		else 
			dp[num] = 2*(nxtD[num]-num)+1+dfs(num-1);
	}
	if(s[num] == 'D') {
		if(preU[num] == -1) 
			dp[num] = num;
		else 
			dp[num] = 2*(num-preU[num])+1+dfs(num+1);
	}
	return dp[num];
}

int main()
{
	scanf("%d",&n);
	scanf("%s",&s[1]);
	int last = -1;
	for(int i = n; i >= 1; i--) {
		nxtD[i] = last;
		if(s[i] == 'D') last = i;
	}
	last = -1;
	for(int i = 1; i <= n; i++) {
		preU[i] =last;
		if(s[i] == 'U') last = i;
	}
	memset(dp, -1, sizeof(dp));
	dp[0] = dp[n+1] = 0;
	for(int i = 1; i <= n; i++) dfs(i);
	for(int i = 1; i <= n; i++) cout << dp[i] << " ";
	cout << endl;
	return 0;
}