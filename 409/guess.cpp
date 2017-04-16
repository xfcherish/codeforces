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

vector<int> nxt[maxn];
bool vis[maxn];


int main()
{
	int m = 200000;
	int cnt = 0;
	for(int i = 1; i <= m; i++) {
		memset(vis, 0, sizeof(vis));
		vis[i] = 1;
		for(int j = 1; j <= m; j++) {
			long long cur = 1;
			cur = cur * i * j % m;
			if(vis[cur] == 0) {
				cnt++;
				nxt[i].push_back(cur);
			}
			else break;
		}
	}
	return 0;
}