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

int d[maxn][maxn];
vector<int> edge[maxn];

struct node {
	vector<PII> path;
	LL sum;
	/* data */
};
vector<node> all_path;
bool vis[maxn];
int n,m,s,t,L;
bool tag;

void dfs(cur,temp_path) {
	vis[cur] = 1;
	temp_path.push_back(cur);
	if(cur == t) {
		LL tmp_sum = 0;
		for(int i = 1; i < temp_path.size(); i++) {
			int vertex1 = temp_path[i];
			int vertex2 = temp_path[i-1];
			if(d[vertex1][vertex2] == 0) {
				tmp_sum  = -1;
			}
			else tmp_sum += d[vertex1][vertex2];
		}
		if(tmp_sum != -1) {
			if(tmp_sum > L) {
				tag = false;
			}
		}
		else {
			one tmp;
			tmp.sum = 0;
			for(int i = 1; i < temp_path.size(); i++) {
				int vertex1 = temp_path[i];
				int vertex2 = temp_path[i-1];
				if(d[vertex1][vertex2] == 0) {
					tmp.path.pb(mp(vertex1,vertex2));
				}
				else tmp.sum += d[vertex1][vertex2];
			}
		}
		return;
	}
	for(int i = 0; i < edge[cur].size(); i++) {
		int nxt = edge[cur][i];
		if(vis[nxt] == 0) {
			dfs(nxt,temp_path);
			vis[nxt] = 0;
		}
	}
}

int main()
{
	int a, b, value;
	cin >> n >> m >> L >> s >> t;
	for(int i = 1; i <= m; i++) {
		cin >> a >> b >> value;
		d[a][b] = d[b][a] = value;
		edge[a].pb(b);
		edge[b].pb(a);
	}
	vector<int> temp_path;
	memset(vis,0,sizeof(vis));
	min_path = (1e9)+10;
	tag = true;
	dfs(s,temp_path);
	if(tag == false) {
		cout << "NO" << endl;
		return 0;
	}
	bool new_tag = false;
	int min_sum = L;
	int min_i = 0;
	for(int i = 0; i < all_path.size(); i++) {
		cout << " path : " << i << endl;
		one cur_path = all_path[i].path;
		for(int j = 1; j < cur_path.size(); j++) {
			int v1 = cur_path[i].first;
			int v2 = cur_path[j].second;
			d[v1][v2] = 1;
			d[v2][v1] = 1;
			all_path[i].sum++;
			// cout << "v2 = " << v2 << endl;
			// cout << "v1 = " << v1 << endl;
		}
		if(all_path[i].sum <= L) {
			new_tag = true;
		}
		if(all_path[i].sum < min_sum) {
			min_sum = all_path[i].sum;
			min_i = i;
		}
	}
	if(new_tag == false) {
		cout << "NO" << endl;
		return 0;
	}
	for(int i = 0; i < all_path[min_i].size(); i++) {
		
	}
	return 0;
}