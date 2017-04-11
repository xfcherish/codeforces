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

const long long inf = (1e11);
const int maxn = (2e5)+100;
const int maxm = (1e5)+10;
int n,m,k;

bool ifend(int x,int y) {
	if(x == 0 && y == 0) return true;
	if(x == 0 && y == m) return true;
	if(x == n && y == 0) return true;
	if(x == n && y == m) return true;
	return false; 
}
struct one {
	int sx,sy,ex,ey;
	long long t1,t2;
};
vector<one> seg;
int a[maxn];
int b[maxn];

long long cal_t(int x, int y, int o) {
	if(o == -1) return -1;
	int sx = seg[o].sx;
	long long  t1 = seg[o].t1;
	long long  t2 = seg[o].t2;
	long long ret = t1 + abs(x-sx);
	if(ret > t2) return -1;
	return ret;
}
int main()
{
	//freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	cin >> n >> m >> k;
	int x,y,nx,ny,dx,dy;
	long long t;
	x = y = 0;
	t = 0;
	dx = dy = 1;
	int len1,len2,len;
	memset(a,-1,sizeof(a));
	memset(b,-1,sizeof(b));
	while(1) {
		one tmp;
		if(dx == 1) len1 = n - x;
		else len1 = x;
		if(dy == 1) len2 = m - y;
		else len2 = y;
		len = min(len1,len2);
		nx = x + len*dx;
		ny = y + len*dy;
		tmp.sx = x;  tmp.sy = y;  tmp.t1 = t;
		tmp.ex = nx;  tmp.ey = ny; tmp.t2 = t+len;
		t = t+len;
		seg.push_back(tmp);
		if(dx*dy == 1) {
			if(a[maxm+x-y] == -1)
				a[maxm+x-y] = seg.size()-1;
		}
		else {
			if(b[x+y] == -1)
				b[x+y] = seg.size()-1;
		}
		if(nx == 0) dx = 1;
		if(nx == n) dx = -1;
		if(ny == 0) dy = 1;
		if(ny == m) dy = -1;
		if(ifend(nx,ny)) break;
		x = nx;
		y = ny;
	}
	for(int i = 1; i <= k; i++) {
		scanf("%d%d",&x,&y);
		//cout << "x-y = " << x-y << endl;
		int i1 = a[maxm+x-y];
		int i2 = b[x+y];
		// cout << "i1 = " << i1 << endl;
		// cout << "i2 = " << i2 << endl;
		long long t1 = cal_t(x,y,i1);
		long long t2 = cal_t(x,y,i2);
		long long ret = inf;
		if(t1 != -1) ret = min(t1,ret);
		if(t2 != -1) ret = min(t2,ret);
		if(ret == inf) cout << -1 << endl;
		else cout << ret << endl;
	}
	return 0;
}