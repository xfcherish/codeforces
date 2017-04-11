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

const int maxn = 5000+10;

vector<int> edge[maxn];
vector<int> cost[maxn];
int n,m,T;
struct one {
	int node,t;
	one(int _node, int _t): node(_node),t(_t) {} 
};
vector<one> ans;
vector<one> seq;
int max_vis;
int cnt[maxn];

void dfs() {
	int len = seq.size();
	int cur = seq[len-1].node;
	if(len < cnt[cur]) return;
	int t = seq[len-1].t;
	if(t > T) return;
	if(cur == n ) {
		if(max_vis < len) {
			max_vis = len;
			ans = seq;
			for(int i = 0; i < seq.size(); i++) {
				int num = seq[i].node;
				cnt[num] = max(cnt[num],i+1);
			}
		}
		return ;
	}
	for(int i = 0; i < edge[cur].size(); i++) {
		int nxt = edge[cur][i];
		int c = cost[cur][i];
		seq.push_back(one(nxt, t+c));
		dfs();
		seq.pop_back();
	}
}

int main()
{
	int i,j,u,v,t;
	cin >> n >> m >> T;
	for(i = 1; i <= m; i++) {
		cin >> u >> v >> t;
		edge[u].push_back(v);
		cost[u].push_back(t);
	}	
	max_vis = 0;
	memset(cnt, 0, sizeof(cnt));
	cnt[1] = 1;
	seq.push_back(one(1,0));
	dfs();
	if(ans.size() == 0) {
		cout << 0 << endl;
		return 0;
	}
	cout << ans.size() << endl;
	for(int i = 0 ; i < ans.size(); i++) {
		cout << ans[i].node << " ";
	}
	cout << endl;
	return 0;
}