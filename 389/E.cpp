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

const int maxn = (1e6)+10;
int n;
int a[maxn];
long long k;

bool judge(int m) {
	long long cnt = 0;
	long long cnt2 = 0;
	for(int i = 1; i <= n; i++) {
		int cur = a[i];
		if(cur >= m) cnt2 = 1;
		else cnt2 = 0;
		while(cur/2 >= m) {
			cur /= 2;
			cnt2 *= 2;
		}
		cnt += cnt2;
	}
	//cout << "m = " << m << " cnt = " << cnt << " k = " << k << endl;
	if(cnt >= k) return true;
	return false;
}

int main()
{
	int l,r,mid;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	l = 1;
	r = 10000000;
	while(l < r) {
		mid = (l+r)/2;
		if(judge(mid) == 1) l = mid+1;
		else r = mid; 
	}
	l--;
	if(l == 0) cout << -1 << endl;
	else cout << l << endl;
	return 0;
}