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

const int maxn =  300010;
int a[maxn],n,cnt;
bool vis[maxn];
vector<int> child[maxn];

void solve(int u, int h) {
	vis[u] = 1;
	cnt ++;
	for(int i = 0; i < child[u].size(); i++) {
		int cur = child[u][i];
		if(vis[cur] == 0) {
			if(a[cur] >= h) {
				solve(cur, h);
			}
		}
	}
}

int main()
{
	int u,v;
	cin >> n;
	int h = -1000000000;
	for(int i = 1; i <= n; i++)  {
		scanf("%d", &a[i]);
		h = max(h,a[i]);
	}
	for(int i = 1; i < n; i++) {
		scanf("%d%d",&u,&v);
		child[u].push_back(v);
		child[v].push_back(u);
	}
	int ans = h;
	for(int i = 1; i <= n; i++) {
		if(ans == h+1) break;
		if(child[i].size() >= 2) {
			int cnt2 = 0;
			for(int j = 0; j < child[i].size(); j++) {
				int cur = child[i][j];
				if(a[cur] == h) {
					cnt2 ++;
				}
				if(cnt2 >= 2) {
					ans = h+1;
					break;
				}
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		if(a[i] == h || a[i] == h-1) {
			if(a[i] == h-1 && ans == h+1) continue;
			int cnt2 = 0;
			for(int j = 0; j < child[i].size(); j++) {
				int cur = child[i][j];
				if(a[cur] >= a[i]) cnt2++;
			}
			if(cnt2 == 1) {
				memset(vis, 0, sizeof(vis));
				cnt = 0;
				solve(i,a[i]);
				// cout << "i = " << i << " cnt = " << cnt << endl;
				if(cnt >= 4)
					ans = max(ans, a[i]+2);
				else if(cnt > 1)
					ans = max(ans, a[i]+1);
				else ans = max(ans, a[i]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}