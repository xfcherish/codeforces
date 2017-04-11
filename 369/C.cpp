#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const long long inf = (1e11)+10;
const int maxn = 105;
long long dp[maxn][maxn][maxn];
int n,m,k;
int c[maxn];
int p[maxn][maxn];

int main()
{
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	int i,j;
	cin >> n >> m >> k;
	for(i = 1; i <= n; i++)
		cin >> c[i];
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= m; j++) {
			cin >> p[i][j];
		}
	}
	memset(dp,-1,sizeof(dp));
	if(c[1] == 0) {
		for(int q = 1 ; q <= m; q++)
			dp[1][1][q] = p[1][q];
	}
	else dp[1][1][c[1]] = 0;
	for(i = 2; i <= n; i++) {
		for(j = 1; j <= k; j++) {
			if(c[i] != 0) {
				for(int q = 1; q <= m; q++) {
					if(c[i] == q) {
						if(dp[i-1][j][q] != -1) {
							if(dp[i][j][q] == -1)
								dp[i][j][q] = dp[i-1][j][q];
							else 
								dp[i][j][q] = min(dp[i][j][q],dp[i-1][j][q]);
						}
					}
					else{
						if(dp[i-1][j-1][q] != -1) {
							if(dp[i][j][c[i]] == -1)
								dp[i][j][c[i]] = dp[i-1][j-1][q];
							else 
								dp[i][j][c[i]] = min(dp[i][j][c[i]], dp[i-1][j-1][q]);
						}
					}
				}
			}
			else {
				for(int q = 1; q <= m; q++) {
					for(int q2 = 1; q2 <= m; q2++) {
						if(q != q2) {
							if(dp[i-1][j-1][q2] != -1) {
								if(dp[i][j][q] == -1)
									dp[i][j][q] = dp[i-1][j-1][q2] + p[i][q];
								else
									dp[i][j][q] = min(dp[i][j][q], dp[i-1][j-1][q2] + p[i][q]);
							}
						}
						else {
							if(dp[i-1][j][q2] != -1) {
								if(dp[i][j][q] == -1)
									dp[i][j][q] = dp[i-1][j][q2] + p[i][q];
								else 
									dp[i][j][q] = min(dp[i][j][q], dp[i-1][j][q2] + p[i][q]);
							}
						}
					}
				}
			}
		}
	}
	// for(i = 1; i <= n; i++) {
	// 	for(j = 1; j <= k; j++) {
	// 		for(int q = 1 ; q <= m; q++) {
	// 			cout << "dp[" << i << "][" << j << "][" << q << "] = " << dp[i][j][q] << endl;
	// 		}
	// 	}
	// }
	long long ans = inf;
	for(int q = 1; q <= m; q++) {
		if(dp[n][k][q] != -1) {
			ans = min(ans, dp[n][k][q]);
		}
	}
	if(ans == inf) 
		ans = -1;
	cout << ans << endl;
	return 0;
}