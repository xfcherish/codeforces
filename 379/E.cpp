#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int maxn = (2e5)+10;

vector<int> child[maxn];
int n,c[maxn];
int cnt[2];
bool vis[maxn];

void dfs(int cur, int color) {
	//cout << "cur = " << cur << " c[cur] = " << c[cur] << " color = " << color << endl;
	if(c[cur] != color) {
		cnt[c[cur]]++;
	}
	vis[cur] = 1;
	for(int i = 0; i < child[cur].size(); i++) {
		int nxt = child[cur][i];
		//cout << "nxt = " << nxt << endl;
		if(vis[nxt] == 1) continue;
		else dfs(child[cur][i],c[cur]);
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	int u,v;
	cin >> n;
	for(int i = 1; i <= n; i++) scanf("%d",&c[i]);
	for(int i = 1; i < n; i++) {
		scanf("%d%d",&u,&v);
		child[u].push_back(v);
		child[v].push_back(u);
	}
	cnt[0] = cnt[1] = 0;
	int root = 1;
	cnt[c[root]]++;
	dfs(root,c[root]);
	cout << "cnt0 = " << cnt[0] << endl;
	cout << "cnt1 = " << cnt[1] << endl;
	cout << min(cnt[0],cnt[1]) << endl;
	return 0;
}