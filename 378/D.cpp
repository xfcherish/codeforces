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
map<PII,vector<int> > dex;
int stone[maxn][3];
int n;

int main()
{
	cin >> n;
	int max_r = 0;
	int max_single = 0;
	int t[3];
	for(int i = 1; i <= n; i++) {
		scanf("%d%d%d", &t[0], &t[1], &t[2]);
		sort(t,t+3);
		for(int j = 0; j < 3; j++) stone[i][j] = t[j];
		dex[make_pair(t[0],t[1])].push_back(i);
		if(t[1] != t[2])
			dex[make_pair(t[0],t[2])].push_back(i);
		if(t[0] != t[2] && (t[0] != t[1]))
			dex[make_pair(t[1],t[2])].push_back(i);
		int now_r = min(min(t[0],t[1]),min(t[1],t[2]));
		if(now_r > max_r) {
			max_r = now_r;
			max_single = i;
		}
	}
	map<PII, vector<int> >::iterator it;
	int max_r2 = 0;
	int max_1,max_2;
	max_1 = max_2 = 0; 
	for(it = dex.begin(); it != dex.end(); it++) {
		int a = it->first.first;
		int b = it->first.second;
		vector<int> v = it->second;
		if(v.size() <= 1 ) continue;
		int now_r = min(a,b);
		vector<pair<LL,int> > tmp;
		for(int i = 0; i < v.size(); i++) {
			LL sum = (LL)stone[v[i]][0] + (LL)stone[v[i]][1] + (LL)stone[v[i]][2];
			LL cur = sum - a - b;
			tmp.push_back(make_pair(cur,v[i]));
		}
		sort(tmp.begin(), tmp.end());
		int m = tmp.size();
		now_r = min(now_r, (int)(tmp[m-1].first + tmp[m-2].first));
		if(now_r > max_r2) {
			max_r2 = now_r;
			max_1 = tmp[m-1].second;
			max_2 = tmp[m-2].second;
		}
	}
	//cout << "max_r = " << max_r << " max_r2 = " << max_r2 << endl;
	if(max_r >= max_r2) {
		cout << 1 << endl;
		cout << max_single << endl;
	}
	else {
		cout << 2 << endl;
		cout << max_1 << " " << max_2 << endl;
	}
	return 0;
}