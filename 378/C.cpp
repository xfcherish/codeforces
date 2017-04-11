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
typedef pair<int,char> PII;

const int maxn = 500+10;
int a[maxn],b[maxn];
int sum[maxn];
int n,k,base;
vector<PII> ans;

bool judge(int l_min, int r) {
	int l = l_min + 1;
	if(l == r) return 1;
	int max_val = 0;
	int pos = 0;
	//cout << "l = " << l << " r = " << r << endl;
	for(int i = l; i <= r; i++) {
		max_val = max(max_val, a[i]);
	}
	for(int i = l; i <= r; i++) {
		if(a[i] == max_val) {
			if(i > l && a[i] > a[i-1]) pos = i;
			if(i < r && a[i] > a[i+1]) pos = i;
		}
	}
	if(pos == 0) return false;
	// cout << "pos = " << pos << endl;
	// cout << "max_val = " << max_val << endl;
	if(pos < r && a[pos] > a[pos+1]) {
		int cnt = 0;
		while(pos != r) {
		//	if(max_val <= a[pos+1]) return false;
			ans.pb(make_pair(base+pos-l+1,'R'));
			max_val += a[pos+1+cnt];
			cnt++;
			r--;
		}
		while(pos != l) {
		//	if(max_val <= a[pos-1]) return false;
			ans.pb(make_pair(base+pos-l+1,'L'));
			max_val += a[pos-1];
			pos--;
		}
	}
	else if(pos > l && a[pos] > a[pos-1]) {
		int cur = pos;
		while(pos != l) {
		//	if(max_val <= a[pos-1]) return false;
			ans.pb(make_pair(base+pos-l+1,'L'));
			max_val += a[pos-1];
			pos--;
		}
		int cnt = 0;
		while(cur != r) {
			ans.pb(make_pair(base+pos-l+1,'R'));
			max_val += a[cur+1+cnt];
			cnt++;
			r--;
		}
	}
	else return false;
	return true;
}

int main()
{	
	cin >> n;
	sum[0] = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
	}
	cin >> k;
	for(int i = 1; i <= k; i++) {
		cin >> b[i];
	}
	int j = 1;
	int last = 0;
	int last_pos = 0;
	for(int i = 1; i <= k; i++) {
		bool tag = false;
		for( ; j <= n; j++) {
			base = i-1;
			if(sum[j] - last == b[i]) {
				//cout << "last_pos = " << last_pos << " j = " << j << endl;
				if(judge(last_pos,j) == false) {
				//	cout << "last_pos = " << last_pos << " j = " << j << endl;
					cout << "NO" << endl;
					return 0;
				}
				last = sum[j];
				last_pos = j;
				tag = true;
				//cout << "ans.size = " << ans.size() << endl;
				break;
			}
		}
		if(tag == false) {
			cout << "NO" << endl;
			return 0;
		}
	}
	if(j != n)  {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	return 0;
}