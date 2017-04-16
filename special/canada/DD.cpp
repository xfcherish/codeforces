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

struct one {
	int order;
	long long t,w;
	one(long long _t, long long _w, int _order) {
		t = _t;
		w = _w;
		order = _order;
	}
};
struct cmp {
	bool operator() (const one & a, const one & b) {
		return (a.w-a.t) > (b.w-b.t);
	}
};
bool cmp2 (const one & a, const one & b) {
	if(a.t != b.t) return a.t > b.t;
	if(a.order == 1 || b.order == 1) 
		return a.order < b.order;
	return (a.w-a.t) < (b.w-b.t);
}

priority_queue<one, vector<one>, cmp> que;
vector<one> team;
int n;

int main()
{
	long long ti,wi;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		//scanf("%d%d",&ti,&wi);
		cin >> ti >> wi;
		team.push_back(one(ti,wi,i));
	}
	sort(team.begin(), team.end(), cmp2);
	int i = 0;
	for( ; ; i++) {
		if(team[i].order == 1) break;
		que.push(team[i]);
	}
	long long cost = 0;
	int cnt = que.size()+1;
	int ans = cnt;
	int now  = i;
	// cout << "cnt = " << cnt << endl;
	for( ; i < n; i++) {
		if(i == n-1) cost += (team[i].t);
		else cost += (team[i].t - team[i+1].t);
		if(i != now)  que.push(team[i]),cnt++;
		// cout << "before i = " << i << " cost = " << cost << endl;
		while(!que.empty()) {
			one u = que.top();
			long long need = u.w + 1 - u.t;
			if(need <= cost) {
				cnt --;
				cost -= need;
				que.pop();
			}
			else break;
			//cout << "need = " << need << endl;
		}
		ans = min(ans,cnt);
	}
	cout << ans << endl;
	return 0;
}