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
int n,nxt;
int a[maxn],b[maxn];

int lcm(int l1, int l2) {
	return l1*l2/__gcd(l1,l2);
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) 
		cin >> a[i];
	memset(b,0,sizeof(b));
	int ans = 1;
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(b[i] == 0) {
			int final = i;
			nxt = a[i];
			cnt = 1;
			b[i] = 1;
		//	cout << "i = " << i << " final = " << final << endl;
			while(nxt != final) {
				// cout << "nxt = " << nxt << endl;
				b[nxt] = 1;
				nxt = a[nxt];
				cnt++;
				if(cnt == 2*n+5) break;
			}
		//	cout << "i = " << i << " cnt = " << cnt << endl;
			if(cnt == 2*n+5) {
				cout << -1 << endl;
				return 0;
			}
			if(cnt % 2 == 0) ans = lcm(ans,cnt/2);
			else ans = lcm(ans,cnt);
		}
	}
	cout << ans << endl;
	return 0;
}