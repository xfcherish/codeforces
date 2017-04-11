#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int maxn = (2e5)+10;
typedef long long LL;
LL n,m,k,x,s;
int a[maxn],b[maxn],c[maxn],d[maxn];

int main()
{
	cin >> n >> m >> k;
	cin >> x >> s;	
	for(int i = 1; i <= m; i++) scanf("%d",&a[i]);
	for(int i = 1; i <= m; i++) scanf("%d",&b[i]);
	for(int i = 1; i <= k; i++) scanf("%d",&c[i]);
	for(int i = 1; i <= k; i++) scanf("%d",&d[i]);
	LL ans = n*x;
	a[0] = x;
	b[0] = 0;
	c[0] = 0;
	for(int i = 0; i <= m; i++) {
		LL xx = a[i];
		if(b[i] > s) continue;
		int pos = upper_bound(d+1,d+k+1,(s-b[i])) - d;
		pos --;
		LL nn = (n - c[pos]);
		ans = min(ans, xx*nn);
	}
	cout << ans << endl;
	return 0;
}