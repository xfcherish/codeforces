#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;

LL n,m;
const int maxn = (1e5)+10;
int rows[maxn],cols[maxn];
int row_num = 0; 
int col_num = 0;

int main()
{
	cin >> n >> m;
	int x,y;
	LL ans = n*n;
	memset(rows,0,sizeof(rows));
	memset(cols,0,sizeof(cols));
	for(int i = 1 ; i <= m; i++) {
		cin >> x >> y;
		if(rows[x] == 0 ) {
			rows[x] = 1;
			ans -= (n - col_num);
			row_num ++ ;
		}
		// cout << " ans  = " << ans << endl;
		if(cols[y] == 0) {
			cols[y] = 1;
			ans -= (n-row_num);
			col_num ++ ;
		}
		cout << ans << endl;
	}
	return 0;
}