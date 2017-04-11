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

const int maxn = (1000)+10;
int a[maxn][maxn],sum1[maxn][maxn],sum2[maxn][maxn];
int n,m;

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1;  j <= m; j++) {
			scanf("%d",&a[i][j]);
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			sum1[i][j] = sum1[i][j-1] + a[i][j];
		}
	}
	for(int j = 1; j <= m; j++) {
		for(int i = 1; i <= n; i++) {
			sum2[i][j] = sum2[i-1][j] + a[i][j];
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(a[i][j] == 0) {
				// up
				if(sum2[i-1][j]) ans++;
				// down
				if(sum2[n][j]-sum2[i][j]) ans++;
				// left
				if(sum1[i][j-1]) ans++;
				// right
				if(sum1[i][m] - sum1[i][j]) ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}