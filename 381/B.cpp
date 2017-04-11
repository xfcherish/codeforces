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

const int maxn = (100)+10;

int n,m;
int a[maxn],b[maxn];

int main()
{
	int l,r;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	memset(b, 0, sizeof(b));
	long long ans = 0;
	for(int i = 1; i <= m; i++) {
		cin >> l >> r;
		for(int j = l; j <= r; j++) {
			b[i] += a[j];
		}
		if(b[i] > 0) ans += b[i];
	}
	cout << ans << endl;
	return 0;
}