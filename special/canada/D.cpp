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

const int maxn = (3e5)+10;

struct one {
	LL t,w,d,order;
	/* data */
};
struct cmp{
    bool operator() (const one & a, const one & b) {
            return a.d > b.d;
    }
};
bool cmp2(const one & a, const one & b) {
	if(a.t != b.t) return a.t > b.t;
	if(a.order == 1 || b.order == 1)
		return (a.order < b.order);
	if(a.d != b.d) return (a.d < b.d);
}
priority_queue<one, vector<one>, cmp> que;
one team[maxn];
int n;

int main()
{
	//freopen("input.txt","r",stdin);
	LL cost;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> team[i].t >> team[i].w;
		team[i].d = team[i].w + 1 - team[i].t;
		team[i].order = i;
	}	
	sort(team+1, team+1+n, cmp2);
	int i = 1;
	while(team[i].order != 1) {
		que.push(team[i]);
		i++;
	}
	int cur = i;
	// cout << "cur = " << cur << endl;
	cost = 0;
	int cnt = que.size()+1;
	int ans = cnt;
	// cout << "cnt = " << cnt << endl;
	for( ; i <= n; i++) {
		if(i+1 > n) 
			cost += team[i].t;
		else cost += (team[i].t - team[i+1].t);
		// cout << "i = " << i << " cost = " << cost << endl;
		if(i > cur) {
			que.push(team[i]);
			cnt++;
		}
		while(!que.empty()) {
			one u = que.top();
			// cout << "u.d = " << u.d << endl;
			if(u.d <= cost) {
				que.pop();
				cnt--;
				cost -= u.d;
			}
			else break;
		}
		// cout << "i = " << i << " cnt = " << cnt << endl;
		ans = min(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}