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

const int maxn = (2e5)+10;
const long long INF = -(2e11);
vector<int> child[maxn];
int n;
int a[maxn];
bool vis[maxn];
LL d[maxn],d2[maxn],ans;

LL dfs(int cur) {
	d[cur] = a[cur];
	vis[cur] = 1;
	for(int i = 0; i < child[cur].size(); i++) {
		int son = child[cur][i];
		if(vis[son] == 0)
			d[cur] += dfs(son);
	}
	return d[cur];
}

LL dfs2(int cur) {
	vis[cur] = 1;
	d2[cur] = d[cur];
	for(int i = 0; i < child[cur].size(); i++) {
		int son = child[cur][i];
		if(vis[son] == 0)
			d2[cur] = max(d2[cur],dfs2(son));
	}
	return d2[cur];
}

void dfs3(int cur) {
	vis[cur] = 1;
	vector<LL> tmp;
	for(int i = 0; i < child[cur].size(); i++) {
		int son = child[cur][i];
		// cout << "son = " << son << endl;
		if(vis[son] == 0) {
			tmp.push_back(d2[son]);
			dfs3(son);
		}
	}
	int len = tmp.size();
	// cout << "len = " << len << endl;
	if(len >=2) {
		sort(tmp.begin(), tmp.end());
		if(ans < tmp[len-1] + tmp[len-2])
			ans = tmp[len-1]+tmp[len-2];
	}
}

int main()
{
	// freopen("input.txt","r",stdin);
	int u,v;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		child[u].push_back(v);
		child[v].push_back(u);
	}
	memset(vis, 0, sizeof(vis));
	dfs(1);
	// for(int i = 1; i <= n; i++) {
	// 	cout << "d[" << i << "]=" << d[i] << endl;
	// }
	memset(vis, 0, sizeof(vis));
	dfs2(1);
	// for(int i = 1; i <= n; i++) {
	// 	cout << "d2[" << i << "]=" << d2[i] << endl;
	// }
	ans = INF;
	memset(vis, 0, sizeof(vis));
	dfs3(1);
	if(ans == INF) 
		cout << "Impossible" << endl;
	else cout << ans << endl;
	return 0;
}
