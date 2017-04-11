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
	long long sumw;
	vector<int> child;
	/* data */
};
one a[maxn];
int n,m;
int ans[maxn],sum[maxn],path[maxn];
int cnt;

void dfs(int cur) {
	int fa = a[cur].fa;
	a[cur].sumw = a[fa].sumw + a[cur].w;
	int v = a[cur].v;
	sum[cur] = ans[cur] = 0;
	for(int i = 0 ; i < a[cur].child.size(); i++) {
		int u = a[cur].child[i];
		path[++cnt] = u;
		dfs(u);
		sum[cur] += sum[u]+1-ans[u];
		cnt--;
	}
	int low,high,mid;
	low = 1;
	high = cnt;
	while(low < high) {
		mid = (low+high)/2;
		long long dis = a[cur].sumw - a[path[mid]].sumw;
		if(v < dis) low = mid + 1;
		else high = mid; 
	}
	ans[path[low]]++;
}

int main()
{
	//freopen("input.txt","r",stdin);
	int o,w;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		scanf("%d",&a[i].v);
		a[i].fa = 0;
		a[i].w = 0;
		a[i].sumw = 0;
	}
	for(int i = 2; i <= n; i++) {
		scanf("%d%d", &o,&w);
		a[o].child.push_back(i);
		a[i].fa = o;
		a[i].w = w;
	}
	memset(ans,0, sizeof(ans));
	cnt = 1;
	path[1] = 1;
	dfs(1);
	for(int i = 1; i <= n; i++) {
		cout << sum[i] << " ";
	}
	cout << endl;
	return 0;
}