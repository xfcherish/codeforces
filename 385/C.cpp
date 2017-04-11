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

const int maxn = (1e3)+10;

int par[maxn],Rank[maxn],c[maxn];
bool vis[maxn], linked[maxn][maxn];
vector<int> v[maxn];
int n,m,k;

void init() {
	for(int i = 0; i <= n; i++) {
		par[i] = i;
		Rank[i] = 0;
	}
}

int find(int x) {
	if(par[x] == x) return x;
	else return par[x] = find(par[x]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x == y) return;
	if(Rank[x] < Rank[y]) {
		par[x] = y;
	}
	else {
		par[y] = x;
		if(Rank[x] == Rank[y]) Rank[x]++;
	}
}

bool same(int x, int y) {
	return find(x) == find(y);
}

int main()
{
	int u1,u2;
	cin >> n >> m >> k;	
	for(int i = 1; i <= k; i++) cin >> c[i];
	init();
	for(int i = 1; i <= m; i++) {
		scanf("%d%d", &u1, &u2);
		unite(u1,u2);
		linked[u1][u2] = linked[u2][u1] = 1;
	}
	int ans = 0;
	memset(vis, 0 , sizeof(vis));
	for(int i = 1; i <= k; i++) {
		v[i].push_back(c[i]);
		vis[c[i]] = 1;
		for(int j = 1; j <= n; j++) {
			if(j != c[i]) {
				if(same(j,c[i])) {
					v[i].push_back(j);
					vis[j] = 1;
				}
			}
		}
	}
	int max_size = 0;
	for(int i = 1; i <= k; i++) {
		int len = v[i].size();
		max_size = max(max_size, len);
		for(int j = 0; j < len; j++) {
			for(int jj = j+1; jj < len; jj++) {
				int cur1 = v[i][j];
				int cur2 = v[i][jj];
				if(linked[cur1][cur2] == 0) {
					ans++;
				}
			}
		}
	}
	vector<int> unvis;
	for(int i = 1; i <= n; i++) 
		if(vis[i] == 0) unvis.push_back(i);
	int len = unvis.size();
	for(int i = 0; i < len; i++) {
		for(int j = i+1; j < len; j++) {
			int cur1 = unvis[i];
			int cur2 = unvis[j];
			if(linked[cur1][cur2] == 0) ans++;
		}
	}
	// cout << "max_size = " << max_size << endl;
	// cout << "len = " << len << endl;
	ans = ans + max_size*len;
	cout << ans << endl;
	return 0;
}