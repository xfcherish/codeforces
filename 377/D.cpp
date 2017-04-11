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
int d[maxn],a[maxn];
vector<int> p[maxn];
int n,m;

struct one {
	int pos,nd;
	one(int _pos, int _nd) {
		pos = _pos;
		nd = _nd;
	}
};

bool cmp(const one & s1, const one & s2) {
	return s1.pos < s2.pos;
}

bool judge(int mid) {
	vector<one> my;
	for(int i = 1; i <= m; i++) {
		int tmp = upper_bound(p[i].begin(), p[i].end(),mid) - p[i].begin();
		//cout << "find i = " << i << " tmp = " << tmp << endl;
		tmp --;
		if(tmp < 0) return false;
		my.push_back(one(p[i][tmp],i));
	}
	sort(my.begin(), my.end(), cmp);
	int len = my.size(); 
	long long cost = 0;
	for(int i = 0; i < len; i++) {
		long long cur_d = my[i].nd;
		long long cur_pos = my[i].pos;
		if(cost + a[cur_d] >= cur_pos) return false;
		cost += (a[cur_d]+1);
	}
	return true;
}

int main()
{
	// freopen("input.txt","r",stdin);
	int i, l, r, mid;
	cin >> n >> m;
	for(i = 1; i <= n; i++) {
		scanf("%d",&d[i]);
		p[d[i]].push_back(i);
	}
	for(i = 1; i <= m; i++) scanf("%d",&a[i]);
	//cout << "done" << endl;
	l = 1;
	r = n;
	if(judge(r) == false) {
		cout << - 1 << endl;
		return 0;
	}
	if(n < m) {
		cout << -1 << endl;
		return 0;
	}
	while(l < r) {
		mid = (l+r)/2;
		//cout << "mid = " << mid << " judge = " << judge(mid) << endl;
		if(judge(mid) == 1) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
	return 0;
}