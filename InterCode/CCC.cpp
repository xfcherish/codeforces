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

const int maxn = (1e5)+10;

// priority_queue<LL> que;
LL sum[maxn];
LL a[maxn];
LL ans[maxn];
int order[maxn];
int n;

LL cal(int low, int high) {
	if(low > high) return 0;
	return sum[high]-sum[low-1];
}

LL query(int low, int high) {
	
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)  {
		cin >> a[i];
		sum[i] = sum[i-1]+a[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> order[i];
		vis[order[i]] = 1;
		ans[i] = query(1,n);
	}
	for(int i = 1; i <= n; i++) 
		cout << ans[i] << endl;
	return 0;
}