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
int n;
int stone[maxn][3];
map<PII, vector<PII> > dict; 

int mmin(int a, int b, int c) {
	return min(min(a,b),min(b,c));
}

int main()
{
	cin >> n;
	int t[3];
	int r1,r2,k0,k1,k2;
	r1 = r2 = 0;
	k0 = k1 = k2 = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d%d%d",&t[0], &t[1], &t[2]);
		sort(t,t+3);
		for(int j = 0; j < 3; j++) stone[i][j] = t[j];
		dict[mp(t[0],t[1])].push_back(mp(t[2],i));
		if(t[1] != t[2])
			dict[mp(t[0],t[2])].push_back(mp(t[1],i));
		if(t[2] != t[0] && t[0] != t[1])
			dict[mp(t[1],t[2])].push_back(mp(t[0],i));
		int cur_r = mmin(t[0],t[1],t[2]);
		if(cur_r > r1) {
			r1 = cur_r;
			k0 = i;
		}
	}
	map<PII, vector<PII> >::iterator it;
	for(it = dict.begin(); it != dict.end(); it++) {
		vector<PII> v = it->second;
		int m = v.size();
		if(m < 2) continue;
		int cur_r = min(it->first.first, it->first.second);
		sort(v.begin(), v.end());
		cur_r =  min(cur_r, (v[m-1].first + v[m-2].first));
		if(cur_r > r2) {
			r2 = cur_r;
			k1 = v[m-1].second;
			k2 = v[m-2].second;
		}
	}
	if(r1 >= r2) cout << 1 << endl << k0 << endl;
	else cout << 2 << endl << k1 << " " << k2 << endl;
	return 0;
}