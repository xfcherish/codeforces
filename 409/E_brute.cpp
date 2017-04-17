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
bool vis[maxn],v[maxn];
vector<int> nxt[maxn];

void dfs(int cur, int dep) {
	vis[cur] = 1;
	cur_len = max(cur_len, dep);
	for(int i = 0; i < nxt[cur].size(); i++) {
		int num = nxt[cur][i];
		if(vis[num] == 0) {
			dfs(num, dep+1);
			vis[num] = 0;
		}
	}
}


int main()
{
	int tmp;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &tmp);
		v[tmp] = 1;
	}
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < m; j++) {
			int cur = i * j % m;
			if(v[cur] == 0)
				nxt[i].push_back(cur);
		}
	}
	for(int i = 0; i < m; i++) {
		memset(vis, 0, sizeof(vis));
		cur_len = 0;
		dfs(i,1);
		cout << "start with " << i << " length = " << cur_len << endl;
	}
	return 0;
}