#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int maxn = 100005;
vector<vector<int> > v(maxn);
int edge[maxn][2];
int color[maxn];
int n,m;


void bfs(int node) {
	queue<int> q;
	q.push(node);
	color[node] = 0;
	while(!q.empty()) {
		int cur = q.front();
		int c = color[cur];
		q.pop();
		for(int i = 0 ; i < v[cur].size(); i++) {
			if(color[v[cur][i]] == -1) {
				color[v[cur][i]] = 1 - c;
				q.push(v[cur][i]);
			}
		}
	}
}


int main() 
{
	int i,j,u1,u2;
	memset(color, -1 ,sizeof(color));
	cin >> n >> m;
	for(i = 1; i <= m; i++) {
		scanf("%d%d", &u1, &u2);
		edge[i][0] = u1;
		edge[i][1] = u2;
		v[u1].push_back(u2);
		v[u2].push_back(u1);
	}
	for(i = 1 ; i <= n; i++) {
		if(color[i] == -1) {
			bfs(i);
		}
	}
	bool flag = true;
	for(i = 1; i <= m; i++) {
		u1 = edge[i][0];
		u2 = edge[i][1];
		if(color[u1] == color[u2]) {
			flag = false;
			break;
		}
	}
	if(flag) {
		vector<int> ans1,ans2;
		for(i = 1; i <= n; i++) {
			if(color[i] == 0)
				ans1.push_back(i);
			else ans2.push_back(i);
		}
		cout << ans1.size() << endl;
		for(i = 0; i < ans1.size(); i++)
			cout << ans1[i] << " ";
		cout << endl;
		cout << ans2.size() << endl;
		for(i = 0; i < ans2.size(); i++)
			cout << ans2[i] << " ";
		cout << endl;
	}
	else cout << - 1 << endl;
}


