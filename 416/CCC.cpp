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
int a[maxn],first[maxn],last[maxn],dp[maxn];
bool vis[maxn];

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		int cur = a[i];
		if(first[cur] == 0) first[cur] = i;
		last[cur] = max(last[cur], i);
	}
	for(int i = 1; i <= n; i++) {
		int cur = a[i];
		dp[i] = dp[i-1];
		if(last[cur] == i) {
			int j = i;
			int now = first[cur];
			int sum = cur;
			memset(vis, 0, sizeof(vis));
			vis[cur] = 1;
			bool tag = true;
			while(j > now) {
				int num = a[j];
				if(vis[num] == 0) {
					vis[num] = 1;
					if(last[num] > i) {
						tag = false;
						break;
					}
					now = min(now , first[num]);
					sum ^= num;
				}
				j--;
			}
			if(tag) dp[i] = max(dp[i], dp[now-1] + sum);
		}
	}
	cout << dp[n] << endl;
	return 0;
}