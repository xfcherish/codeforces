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

// priority_queue<LL> que;
LL sum[maxn];
LL a[maxn];
LL ans[maxn];
int order[maxn];
int n;
LL max_val;

struct one {
	bool vis;
	LL val;
	int l,r;
};
one left[maxn],right[maxn];

LL cal(int low, int high) {
	if(low > high) return 0;
	return sum[high]-sum[low-1];
}
void dfs(int low, int high, int num) {
	if(num == n+1) return;
	int cur = order[num];
	if(low <= cur && cur <= high) {
		ans[num] = max(ans[num],cal(low,cur-1));
		ans[num] = max(ans[num],cal(cur+1,high));
		dfs(low,cur-1,num+1);
		dfs(cur+1,high,num+1);
	}
	else{ 
		ans[num] = max(ans[num],cal(low,high));
		dfs(low,high,num+1);
	}
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)  {
		cin >> a[i];
		sum[i] = sum[i-1]+a[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> order[i];
	}
	for(int i = 1; i <= n; i++) {
		left[i].tag = false;
		right[i].tag = false;
		left[i].l = right[i].l = i;
		left[i].r = right[i].r = i;
		left[i].sum = right[i].l = i;
		left[i].s = right[i].s = a[i];
	}
	max_val = 0;
	for(int i = n; i >= 1; i--) {
		ans[i] = max(ans[i],max_val);
		int cur = order[i];
		if(cur < n) {
			if(right[cur+1].tag) {
				right[cur].tag = 1;
				right[cur].l = cur;
				right[cur].r = right[cur+1].r;
				right[cur].val = right[cur+1].val+a[cur];
				max_val = max(max_val, right[cur].val);
				left[]
			}
			else {
				right[cur].tag = 1;
				right
			}
		}
	}
	for(int i = 1; i <= n; i++) 
		cout << ans[i] << endl;
	return 0;
}