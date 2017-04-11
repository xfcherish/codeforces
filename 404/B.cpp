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


int n,m;
int minr[2],maxl[2];

int main()
{
	int l,r;
	for(int i = 0; i < 2; i++) {
		minr[i] = inf;
		maxl[l] = 0;
	}
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> l >> r;
		minr[0] = min(r, minr[0]);
		maxl[0] = max(l, maxl[0]);
	}
	cin >> m;
	for(int i = 1; i <= m; i++) {
		cin >> l >> r;
		minr[1] = min(r, minr[1]);
		maxl[1] = max(l, maxl[1]);
	}
	int ans = 0;
	if(maxl[1] > minr[0])
		ans = max(ans, maxl[1] - minr[0]);
	if(maxl[0] > minr[1]) 
		ans = max(ans, maxl[0] - minr[1]);
	cout << ans << endl;
	return 0;
}