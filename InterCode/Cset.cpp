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

typedef long long ll;
const int inf = 0x3f3f3f3f;

multiset<long long> S;
set<pair<int, int> > P;

int n;
int a[300001];
long long sum[300001];
int x;

typedef set<pair<int, int> > :: iterator iter;
int main( ) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i];
	S.insert(sum[n]);
	P.insert(make_pair(n, 1));
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &x);
		iter tt = P.lower_bound(make_pair(x, 0));
		pair<int, int> tmp = (*tt);
		int l = tmp.second, r = tmp.first;
		
		long long tx = sum[r] - sum[l - 1];
		S.erase(S.find(tx));
		P.erase(tt);
		if (l <= x - 1) {
			P.insert(make_pair(x - 1, l));
			S.insert(sum[x - 1] - sum[l - 1]);
		}
		if (x + 1 <= r) {
			P.insert(make_pair(r, x + 1));
			S.insert(sum[r] - sum[x]);
		}
		if (S.empty()) printf("0\n");
		else printf("%lld\n", *(-- S.end()));
	}
	return 0;
}