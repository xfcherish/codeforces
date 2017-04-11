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

int a[25][25],b[25][25];
int cnt[25][25];
int n,m;
int num ;

void dfs(int dep, vector<int> v) {
	if(dep == m+1) {
		int now = 0;
		for(int i = 0; i < v.size(); i++) {
			for(int j = 1; j <= n; j++) 
				b[j][i+1] = a[j][v[i]];
			if(v[i] != (i+1)) {
				now++;
			}
		}
		for(int i = 1; i <= n; i++) {
			int tmp = 0;
			for(int j = 1; j <= m; j++) {
				if(b[i][j] != j) tmp++;
			}
			now += (tmp-1);
		}
		// for(int i = 0; i < v.size(); i++)
		// 	cout << v[i] << " ";
		//cout << "now = " << now << endl;
		num = min(now,num);
	}
	int max_val = 0;
	for(int i = 1; i <= m; i++) {
		max_val = max(max_val, cnt[dep][i]);
	}
	bool vis[26];
	memset(vis, 0 , sizeof(vis));
	for(int i = 0; i < v.size(); i++)
		vis[v[i]] = 1;
	for(int i = 1; i <= m; i++) {
		if(vis[i]) continue;
		if(max_val == cnt[dep][i]) {
			vector<int> cur = v;
			cur.push_back(i);
			dfs(dep+1,cur);
		}
	}
}

int main()
{
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	int i,j;
	memset(cnt, 0, sizeof(cnt));
	cin >> n >> m;
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= m; j++) {
			cin >> a[i][j];
			cnt[j][a[i][j]]++;
		}
	}
	num = 100000000;
	vector<int> v;
	dfs(1,v);
	if(num <= n+1) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}