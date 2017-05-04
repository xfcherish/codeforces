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

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1010;

int n,m,si,sj,ti,tj;
string s[maxn];
vector<pii> s1,t1;

void dfs1(int i, int j, int d) {
	if(i < 0 || i >= n) return ;
	if(j < 0 || j >= m) return ; 
	// cout << "s[" << i << "][" << j << "]=" << s[i][j] << endl;
 	if(s[i][j] == '*') return;
 	// cout << "i = " << i << " j = " << j << endl;
	if(i != si || j != sj) 
		s1.push_back(mp(i,j));
	if(d == 0) dfs1(i+1,j,0);
	if(d == 1) dfs1(i-1,j,1);
	if(d == 2) dfs1(i,j+1,2);
	if(d == 3) dfs1(i,j-1,3); 
}

void dfs2(int i, int j, int d) {
	if(i < 0 || i >= n) return ;
	if(j < 0 || j >= m) return ; 
	if(s[i][j] == '*') return;
	if(i != ti || j != tj) t1.push_back(mp(i,j));
	if(d == 0) dfs2(i+1,j,0);
	if(d == 1) dfs2(i-1,j,1);
	if(d == 2) dfs2(i,j+1,2);
	if(d == 3) dfs2(i,j-1,3); 
}

bool judge(int t, int c, int a, int b) {
	if(t == 0) {
		for(int i = min(a,b); i <= max(a,b); i++) {
			if(s[c][i] == '*') return false;
		}
		return true;
	}
	else{
		for(int i = min(a,b); i <= max(a,b); i++) {
			if(s[i][c] == '*') return false;
		}
		return true;
	}
}

int main()
{	
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> s[i];
		for(int j = 0; j < m; j++) {
			if(s[i][j] == 'S') {
				si = i;
				sj = j;
			}
			if(s[i][j] == 'T') {
				ti = i;
				tj = j;
			}
		}
	}
	for(int i = 0; i < 4; i++) {
		dfs1(si,sj,i);
		dfs2(ti,tj,i);
	}
	// cout << "s1 size = " << s1.size() << endl;
	// cout << "t1 size = " << t1.size() << endl;
	bool tag = false;
	for(int i = 0 ; i < s1.size(); i++) {
		// cout << "si = " << s1[i].first << " sj = " << s1[i].second << endl;
		if(s1[i].first == ti && s1[i].second == tj) {
			tag = true;
			break;
		}
		for(int j = 0; j < t1.size(); j++) {
			if(s1[i] == t1[j]) {
				tag = true;
				break;
			}
			else if(s1[i].first == t1[j].first) {
				if(judge(0,s1[i].first, s1[i].second, t1[j].second)) {
					tag = true;
					break;
				}
			}
			else if(s1[i].second == t1[j].second) {
				if(judge(1,s1[i].second, s1[i].first, t1[j].first)) {
					tag = true;
					break;
				}
			}
		}
	}
	if(tag) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}