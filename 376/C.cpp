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
int n,m,k;
int l[maxn],r[maxn];
int c[maxn];
int same[maxn];
vector<int> v[maxn];
int par[maxn],rank[maxn];

void init() {
	for(int i = 0; i < n; i++) {
		par[i] = i;
		rank[i] = 0;
	}
}

int find(int x) {
	if(par[x] == x) return x;
	else return par[x] = find(par[x]);
}

void unite(int x,int y) {
	x = find(x);
	y = find(y);
	if(x == y) return;
	if(rank[x] < rank[y]) {
		par[x] = y;
	}
	else {
		par[y] = x;
		if(rank[x] == rank[y]) rank[x]++;
	}
}

bool same(int x, int y) {
	return find(x) == find(y);
}

int change(int pos) {
	int total = v[pos].size();
	int max_c = 0;
	vector<int> color;
	for(int i = 0; i < total; i++)
		color.push_back(c[v[pos][i]]);
	sort(color.begin(), color.end());
	int cnt = 1;
	for(int i = 1; i < total; i++) {
		if(color[i] == color[i-1]) {
			cnt++;
			max_c = max(max_c, cnt);
		}
		else {
			max_c = max(max_c, cnt);
			cnt = 0;
		}
	}
	// cout << "max_c = " << max_c << endl;
	// cout << "total = " << total << endl;
	return total - max_c;
}

int main()
{
	int i;
	cin >> n >> m >> k;
	for(i = 0; i < n; i++) scanf("%d",&c[i]);
	memset(same, 0, sizeof(same));
	init();
	for(i = 0; i < m; i++) {
		scanf("%d%d",&l[i],&r[i]);
		unite(l[i],r[i]);
	}
	cnt = 1;
	for(int i = 0; i < m; i++) {
		if(find(l[i],r[i])) 
	}
	for(int i = 1; i <= n; i++) {
		v[same[i]].push_back(i);
	}
	int ans = 0;
	//cout << "cnt = " << cnt << endl;
	for(int i = 1; i < cnt; i++) {
		ans += change(i);
	}
	cout << ans << endl;
	return 0;
}






