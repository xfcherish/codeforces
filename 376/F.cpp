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
int a[maxn];
long long sum[maxn];
long long ans[maxn];
int n;

long long solve(int pos) {
	if(pos == 0) return 0; 
	if(pos == n+1) return 0;
	long long ans = sum[n] - sum[pos-1];
	for(int i = pos + 1; i <= n; i++)
		ans -= (a[i]%a[pos]);
	return ans;
}
int main()
{
	cin >> n;
	sum[0] = 0;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+1+n);
	for(int i = 1; i <= n; i++) {
		sum[i] = sum[i-1]+a[i];
	}
	int l,r,mid;
	l = 1;
	r = n;
	LL pre_val,now_val,next_val;
	while(l < r) {
		mid = (l+r)/2;
		//cout << "l = " << l << " mid = " << mid << " r = " << r << endl;
		pre_val = solve(mid-1);
		now_val = solve(mid);
		next_val = solve(mid+1);
		// cout << "pre_val = " << pre_val << endl;
		// cout << "now_val = " << now_val << endl;
		// cout << "next_val = " << next_val << endl;
		if(now_val >= pre_val && now_val >= next_val) {
			break;
		}
		else if(pre_val <= now_val && now_val <= next_val) {
			l = mid+1;
		}
		else if(pre_val >= now_val && now_val >= next_val) {
			r = mid-1;
		}
	}
	mid = (l+r)/2;
	now_val = solve(mid);
	for(int i = 1;  i <= min(10,n); i++) {
		now_val = max(now_val, solve(i));
	}
	cout << now_val << endl;
	return 0;
}