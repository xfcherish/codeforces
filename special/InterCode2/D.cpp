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
int dp[maxn],n,m;
string s,str,ans_s;
vector<int> pos[26];

void dfs(int dep) {
	if(dep + m > n-1)
	cout << "str = " << str << " dep = " << dep << endl;
	if(dp[dep] == -1) {
		dp[dep] = str.length();
	}
	else {
		if(dp[dep] < str.length()) return;
		else if(dp[dep] >= str.length()) {
			dp[dep] = str.length();
		}
	}
	if(dep + m > n-1) {
		if(str.length() <= ans_s.length()) {
			sort(str.begin(),str.end());
			ans_s = min(ans_s, str);
		}
		return ;
	} 
	for(int i = dep+1; i <= dep+m; i++) {
		string new_s = str;
		str = str + s[i];
		dfs(i);
		str = new_s;
	}
}

int main()
{
	cin >> m >>  s;
	n = s.length();
	for(int i = 0; i < n; i++ ) {
		int cur = s[i]-'a';
		pos[cur].pb(cur);
	}
	for(int i = 0; i < 26; i++) {
		sort(pos[i].begin(), pos[i].end());
	}
	ans_s = s;
	memset(dp, -1, sizeof(dp));
	dfs(-1);
	cout << ans_s << endl;
	return 0;
}