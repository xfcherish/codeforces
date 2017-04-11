#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1000010;
int a[maxn],b[maxn],c[maxn];
int vis[maxn];
int n;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) {
		scanf("%d",&a[i]);
		// c[a[i]] = i;
		b[i] = i-1;
	}
	memset(vis,0,sizeof(vis));
	vis[0] = 1;
	vis[1] = 1;
	int cur = 1;
	int cnt = 0;
	while(vis[a[cur]] == 0) {
		cur = a[cur];
		cnt++;
		b[cur] = min(b[cur], cnt);
		for(int i = 1; i <= n; i++)
			b[i] = min(b[i], b[cur]+ abs(cur-i));
		vis[cur] = 1;
	}
	for(int i = 1; i <=n ; i++) {
		printf("%d ",b[i]);
	}
	cout << endl;
	return 0;
}