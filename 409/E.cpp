#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>

using namespace std;

# define pb push_back
# define mp make_pair

typedef long long ll;
typedef pair<int,int> PII;

const int maxn =  200005;

int n,m;
int ban[maxn],cnt[maxn],dp[maxn],pre[maxn];
vector<int> g[maxn],d,ans;

ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}

ll extend_gcd(ll a, ll b, ll &x, ll &y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	else {
		ll r = extend_gcd(b, a % b, y, x);
		y -= x*(a/b);
		return r;
	}
}

void dfs(int cur) {
	if(cur == -1) return;
	for(int i = 0; i < g[d[cur]].size(); i++) {
		ans.push_back(g[d[cur]][i]);
	}
	dfs(pre[cur]);
}

ll inv(ll a, ll mod) {
	if(a == 0) return 0;
	ll a1 = a, b1 = mod, x = 1, y = 1;
	extend_gcd(a1, b1, x, y);
	x = (x % mod + mod ) % mod;
	// cout << "a = " << a << " mod = " << mod << " x = " << x << endl;
	return x;
}


int from_to(int x, int y, int mod) {
	int c = gcd(x,mod);
	x /= c;  y /= c;  mod /= c;
	int ans = y * inv(x, mod) % mod;
	// cout << "x = " << x << " k = " << ans << " y = " 
	// 	<< y << " mod = " << mod << endl;
	return ans;
}

int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int tmp;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> tmp;
		ban[tmp] = 1;
	}	
	for(int i = 0; i < m; i++) {
		if(ban[i] == 0) {
			g[gcd(i,m)].push_back(i);
			cnt[gcd(i,m)]++;
		}
	}
	for(int i = 1; i <= m; i++) {
		if(m % i == 0) 
			d.push_back(i);
	}
	memset(pre, -1 , sizeof(pre));
	for(int i = 0; i < d.size(); i++) {
		for(int j = 0; j < i; j++) {
			if(d[i] % d[j] == 0) {
				if(dp[j] > dp[i]) {
					dp[i] = dp[j];
					pre[i] = j;
				}
			}
		}
		dp[i] += cnt[d[i]];
		// cout << "d[" << i << "]=" << d[i] << " dp[" << i << "]=" << dp[i] << endl;
	}
	cout << dp[d.size()-1] << endl;
	dfs(d.size()-1);
	reverse(ans.begin(), ans.end());
	int last = 1;
	for(int i = 0; i < ans.size(); i++) {
		cout << from_to(last, ans[i],m) << " ";
		last = ans[i];
	}
	cout << endl;
	return 0;
}