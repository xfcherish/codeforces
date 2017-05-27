#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>

using namespace std;

# define pb push_back
# define mp make_pair

typedef long long ll;
typedef pair<int,int> PII;

const int maxn =  10000;

int n;
int a[maxn];
int dp[maxn];

struct one
{	
	int l,r,v;
};
one p[maxn];

int f(int n1, int cur) {
	int l = p[cur].l;
	int r = p[cur].r;
	int v = p[cur].v;
	int ans = v;
	for(int i = l-1; i > n1; i--) {
		int cur2 = a[i];
		if(p[cur2].l <= n1 || p[cur2].r > r) break;
		v = v ^ p[cur2].v;
		i = p[cur2].l;
		ans = max(ans, v);
	}
	return ans;
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 0; i <= 5000; i++) 
		p[i].l = p[i].r = p[i].v = 0;
	for(int i = 1; i <= n; i++) {
		int cur = a[i];
		if(p[cur].l == 0)
			p[cur].l = i;
		p[cur].r = max(p[cur].r, i);
	}
	for(int i = 0; i <= 5000; i++) {
		set<int> s;
		for(int j = p[i].l; j <= p[i].r ; j++) {
			s.insert(a[j]);
		}
		for(set<int>::iterator it = s.begin(); it != s.end(); it++) {
			p[i].v = p[i].v ^ (*it);
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int cur = a[i];
		if(i != p[cur].r) continue;
		else {
			int ll = p[cur].l;
			for(int j = 0; j < ll; j++) {
				dp[i] = max(dp[i], dp[j] + f(j ,cur));
			}
		}
		// cout << "dp[" << i << "]=" << dp[i] << endl;
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}