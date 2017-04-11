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

const int maxn = (1e5)+10;
int d[maxn],a[maxn];
int n,m;
bool vis[maxn];
int last_pos[maxn];
int prepare[maxn];

bool judge(int mid) {
	vector<int> my;
	memset(vis, 0, sizeof(vis));
	memset(last_pos, 0 , sizeof(last_pos));
	for(int i = 1; i <= mid; i++) { 
		vis[d[i]] = 1;
		last_pos[d[i]] = i;
	}
	for(int i = 1; i <= mid; i++) {
		if(vis[d[i]] && d[i] && i == last_pos[d[i]]) {
			my.push_back(last_pos[d[i]]);
			prepare[last_pos[d[i]]] = a[d[i]];
		}
	}
	sort(my.begin(), my.end());
	if(my.size() < m) return 0;
	long long cost = 0;
	for(int i = 0; i < m; i++) {
		int t = my[i];
		int p = prepare[t];
		if(cost + p >= t) return 0;
		cost = cost + p + 1;
	}
	return true;
}

int main()
{
	// freopen("input.txt","r",stdin);
	int i, l, r, mid;
	cin >> n >> m;
	for(i = 1; i <= n; i++) scanf("%d",&d[i]);
	for(i = 1; i <= m; i++) scanf("%d",&a[i]);
	//cout << "done" << endl;
	l = 1;
	r = n;
	if(judge(r) == false) {
		//cout << "hehe" << endl;
		cout << - 1 << endl;
		return 0;
	}
	while(l < r) {
		mid = (l+r)/2;
		//cout << "mid = " << mid << " judge = " << judge(mid) << endl;
		if(judge(mid) == 1) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
	return 0;
}