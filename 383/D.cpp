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

const int maxn = 1010;
int n,m,W,cnt;
int b[maxn],w[maxn];
int l[maxn][maxn];
int nb[maxn],nw[maxn];
int dp[maxn][maxn];
vector<int> v[maxn];

int main()
{
	// freopen("input.txt","r",stdin);
	int x,y;
	cin >> n >> m >> W;
	for(int i = 1; i <= n; i++) scanf("%d",&w[i]);
	for(int i = 1; i <= n; i++) scanf("%d",&b[i]);
	memset(l,0,sizeof(l));
	memset(nb,0,sizeof(nb));
	memset(nw,0,sizeof(nw));
	for(int i = 1; i <= m; i++) {
		scanf("%d%d",&x,&y);
		l[x][y] = l[y][x] = 1;
	}
	cnt = 0;
	for(int i = 1; i <= n; i++) {
		bool tag = true;
		for(int j = 1; j <= cnt; j++) {
			for(int k = 0; k < v[j].size(); k++) {
				int cur = v[j][k];
				if(l[cur][i] == 1) {
					v[j].push_back(i);
					tag = false;
					break;
				}
			}
			if(tag == false) break;
		}
		if(tag == true) {
			cnt++;
			v[cnt].push_back(i);
		} 
	}
	for(int i = 1; i <= cnt; i++) {
		for(int j = 0; j < v[i].size(); j++) {
			int cur = v[i][j];
			nb[i] += b[cur];
			nw[i] += w[cur];
		}
	}
	cout << "cnt = " << cnt << endl;
	for(int i = 1; i <= cnt ; i++) {
		cout << "i = " << i << " ";
		for(int j = 0; j < v[i].size(); j++)
			cout << v[i][j] << " ";
		printf("b[%d] = %d w[%d]=%d\n",i,nb[i],i,nw[i]);
	}
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= cnt; i++) {
		for(int j = 0; j <= W; j++) {
			dp[i][j] = max(dp[i-1][j], dp[i][j]);
			if(j >= nw[i])
				dp[i][j] = max(dp[i][j], dp[i-1][j-nw[i]]+nb[i]);
			for(int k = 0; k < v[i].size(); k++) {
				int cur = v[i][k];
				if(j >= w[cur])
					dp[i][j] = max(dp[i][j], dp[i-1][j-w[cur]]+b[cur]);
			}
		//	cout << "dp[" << i << "][" << j << "]=" << dp[i][j] << endl;
		}
	}
	int ans = 0;
	for(int i = 0; i <= W; i++) 
		ans = max(ans, dp[cnt][i]);
	cout << ans << endl;
	return 0;
}