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

int n;
string s;
bool vis[maxn];

int main()
{
	cin >> n >> s;
	int D,R,d,r;
	D = R = 0;
	memset(vis, 1, sizeof(vis));
	for(int i = 0; i < n; i++) {
		if(s[i] == 'D') D++;
		else R++;
	}
	d = 0;
	r = 0;
	for(int i = 0 ; D != 0 && R != 0; i = (i+1)%n ) {
		if(s[i] == 'D') {
			if(r > 0) {
				r--;
				s[i] = '.';
				D--;
			}
			else d++;
		}
		if(s[i] == 'R') {
			if(d > 0) {
				d--;
				s[i] = '.';
				R--;
			}
			else r++;
		}
	}
	if(D == 0) cout << "R" << endl;
	else cout << "D" << endl;
	return 0;
}