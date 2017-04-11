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

int n,q;
int t[maxn],k[maxn],d[maxn];
int last[105];


int main()
{
	cin >> n >> q;
	for(int i = 1; i <= q; i++) {
		scanf("%d%d%d", &t[i], &k[i], &d[i]);
	}
	for(int i = 1; i <= q; i++) {
		int cnt = 0;
		int sum = 0;
		int kk = k[i];
		for(int j = 1; j <= n; j++) {
			if(last[j] < t[i]) {
				cnt++;
			}
		}
		if(cnt < kk) cout << -1 << endl;
		else {
			for(int j = 1; j <= n; j++) {
				if(last[j] < t[i]) {
					// cout << "i = " << i << " j = " << j << endl;
					last[j] = (t[i]+d[i]-1);
					kk --;
					sum += j;
				}
				if(kk == 0) break;
			}
			cout << sum << endl;
		}
	}
	return 0;
}