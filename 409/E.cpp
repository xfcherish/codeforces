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

const int maxn =  200005;

int n,m, cur_len;
bool vis[maxn];
vector<int> nxt[maxn];
vector<int> v;
int d[maxn];

int dfs(int cur) {
	cout << "cur = " << cur << endl;
	vis[cur] = 1;
	if(d[cur] != -1) return d[cur];
	for(int i = 0; i < nxt[cur].size(); i++) {
		int nxt_node = nxt[cur][i];
		if(vis[nxt_node] == 0) {
			d[cur] = max(d[cur], 1 + dfs(nxt_node));
			vis[nxt_node] = 0;
		}
	}
	return d[cur];
}

int main()
{
	int tmp;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &tmp);
		vis[tmp] = 1;
	}
	for(int i = 0; i < m ; i++) {
		if(vis[tmp] == 0) v.push_back(i);
	}
	int len  = v.size();
	cout << "len = " << len << endl;
	for(int i = 0; i < v.size(); i++) {
		cout << "v[" << i << "]=" << v[i] << endl;
	}
	for(int i = 0; i < m; i++) {
		memset(vis, 0, sizeof(vis));
		vis[i] = 1;
		for(int j = 0; j < len; j++) {
			long long cur = 1;
			cur = cur * i * v[j] % m;
			cout << "i = " << i << " v[" << j << "]=" << v[j] << endl;
			cout << "i = " << i << " cur = " << cur << endl;
			if(cur != i) {
				nxt[i].push_back(cur);
			}
		}
	}
	for(int i = 0; i < m; i++) {
		cout << "nxt[" << i << "] size = " << nxt[i].size() << endl;
		for(int j = 0; j < nxt[i].size(); j++) {
			cout << nxt[i][j] << " ";
		}
		cout << endl;
	}
	int ans = 0;
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < len; i++) {
		memset(d, -1 , sizeof(d));
		dfs(v[i]);
		ans = max(ans, d[v[i]]);
	}
	cout << ans << endl;
	return 0;
}