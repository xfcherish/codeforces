#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

pair<int,int> PII;

int n,ans;
string s;
int cnt[52];

int tran(char c) {
	if(c <= 'Z' && c >= 'A')
		return (c-'A'+26);
	if(c <= 'z' && c >= 'a')
		return (c-'a');
	return -1;
}
void dfs(int l, int r) {
	if(l == r) {
		ans = min(ans, (r-l)+1);
		return;
	}
	if(cnt[tran(s[r])] <= 1 && cnt[tran(s[l])] <= 1) {
		ans = min(ans, (r-l)+1);
		return;
	}
	if(cnt[tran(s[r])] > 1) {
		cnt[tran(s[r])]--;
		dfs(l,r-1);
		cnt[tran(s[r])]++;
	}
	if(cnt[tran(s[l])] > 1) {
		cnt[tran(s[l])]--;
		dfs(l+1,r);
		cnt[tran(s[l])]++;
	}
}

int main()
{
	cin >> n >> s;
	for(int i = 0; i < s.length(); i++) {
		cnt[tran(s[i])]++;
	}
	ans = n;
	dfs(0,n-1);
	cout << ans << endl;
	return 0;
}