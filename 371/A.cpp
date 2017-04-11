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

int main()
{
	LL l1,l2,r1,r2,k;
	cin >> l1 >> r1 >> l2 >> r2 >> k;
	LL left = max(l1,l2);
	LL right = min(r1,r2);
	if(left > right) {
		cout << 0 << endl;
	}
	else {
		LL ans = (right - left  + 1) ;
		if(k <= right && k >= left)
			ans --;
		cout << ans << endl;
	}
	return 0;
}