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
const int inf = (1e9)+10;
int n,k,s,t;
int c[maxn],v[maxn],g[maxn];

bool judge(int mid) {
	long long cost_t = 0;
	for(int i = 1; i <= k+1; i++) {
		long long dis = g[i]-g[i-1];
		if(dis > mid) return false;
		else if(2*dis <= mid) cost_t += dis;
		else cost_t += (3*dis - mid);
	}
	if(cost_t > t) return false;
	return true;
}

int main()
{
	int i,j,low,mid,high;
	cin >> n >> k >> s >> t;
	for(i = 1; i <= n; i++) scanf("%d%d",&c[i],&v[i]);
	for(i = 1; i <= k; i++) scanf("%d",&g[i]);
	sort(g+1,g+1+k);
	g[0] = 0;
	g[k+1] = s;
	low = 1;
	high = 2*(s+1);
	while(low < high) {
		mid = low + (high-low)/2;
	//	cout << "low = " << low << " high = " << high << " mid = " << mid << endl;
		if(judge(mid)) high = mid;
		else low = mid+1;
	}
//	cout << "low = " << low << endl;
	if(judge(low) == false) low++;
	if(judge(low) == false) low = inf;
	int ans = inf;
	for(i = 1; i <= n; i++) {
		if(v[i] >= low) ans = min(ans,c[i]);
	}
	if(ans == inf) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}