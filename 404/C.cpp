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

LL l,r,mid,n,m;

LL cal(LL t) {
	if(t > (LL)(sqrt(2*(n-m))))
		return (n-m+1);
	LL ans = (t+1)*t/2;
	return ans;
}

int main()
{
	cin >> n >> m;
	if(n <= m) {
		cout << n << endl;
		return 0;
	}
	l = m+1;
	r = n;
	while(l < r) {
		mid = (l+r)/2;
		if(cal(mid-m) < n-m) l = mid+1;
		else r = mid;
		// cout << "l = " <<  l << " r = " << r << endl;
	}
	cout << l << endl;
	return 0;
}





