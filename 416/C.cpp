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
vector<one> p2;

bool cmp(const one &s1, const one & s2) {
	return s1.l < s2.l;
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
		if(p[i].l != 0) {
			p2.push_back(p[i]);
		}
	}
	sort(p2.begin(), p2.end(),cmp);
	int ans = 0;
	int m = p2.size();
	for(int i = 0; i < m; i++) {
		dp[i] = p2[i].v;
		for(int j = 0; j < i; j++) {
			if(p2[i].l > p2[j].r)
				dp[i] = max(dp[i], dp[j] + p2[i].v);
		}
		// if(dp[i] != 0) {
		// 	cout << "i = " << i << " l = " << p[i].l << " r = " << p[i].r << " v = " << p[i].v << endl;
		// 	cout << "dp = " << dp[i] << endl;
		// }
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}