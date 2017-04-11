#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef unsigned long long LL;

const int maxn = (1e5)+10;
int n,k;
int a[maxn],c[maxn], d[maxn];
LL sum;
bool vis[maxn];

int neigh(int pos) {
	if(pos == 1) 
		return a[n]+a[2];
	if(pos == n)
		return a[1]+a[n-1];
	return a[pos-1]+a[pos+1];
}

int main()
{
	int i,j;
	cin >> n >> k;
	sum = 0;
	LL res = 0;
	for(i = 1; i <= n; i++) {
		scanf("%d",&a[i]);
		sum += a[i];
	}
	for(i = 1 ; i <= k; i++) {
		scanf("%d",&c[i]);
	}
	for(i = 1; i < n; i++) {
		res += (LL)a[i]*a[i+1];
	}
	res += a[n]*a[1];
	d[1] = 0;
	for(i = 2; i <= k; i++) {
		d[i] = d[i-1]+ a[c[i-1]];
	}
	// cout << "sum = " << sum << endl;
	for(i = 1; i <= k; i++) {
		int now = c[i];
		vis[now] = 1;
		res -= a[now]*d[i];
		res += a[now]*(sum-a[now]);
		int left = (now-2+n)%n + 1;
		int right = now % n + 1;
		if(vis[right] == 0)
			res -= a[now]*a[right];
		if(vis[left] == 0)
			res -= a[now]*a[left];
	}
	cout << res << endl;
	return 0;
}