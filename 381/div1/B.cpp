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

const int maxn = (2e5)+10;

struct one {
	int fa,v,w;
	vector<int> child;
	/* data */
};
one a[maxn];
int n,m;
int ans[maxn];

void go_up(int cur, int remain) {
	if(cur == 0) return;
	if(remain < 0) return ;
	ans[cur]++;
	go_up(a[cur].fa, remain - a[cur].w);
}

int main()
{
	int o,w;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		scanf("%d",&a[i].v);
		a[i].fa = 0;
		a[i].w = 0;
	}
	for(int i = 2; i <= n; i++) {
		scanf("%d%d", &o,&w);
		a[o].child.push_back(i);
		a[i].fa = o;
		a[i].w = w;
	}
	memset(ans,0, sizeof(ans));
	for(int i = 1; i <= n; i++) {
		int fa = a[i].fa;
		go_up(fa, a[i].v - a[i].w);
	}
	for(int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}