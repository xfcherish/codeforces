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
int n,m;
string s,str;
vector<int> pos[26];

int main()
{
	cin >> m >>  s;
	n = s.length();
	for(int i = 0; i < n; i++ ) {
		int cur = s[i]-'a';
		pos[cur].pb(i);
	}
	for(int i = 0; i < 26; i++)
		sort(pos[i].begin(), pos[i].end());
	int i = -1;
	while(i + m < n) {
		int start = i+1;
		int last = i+m;
		for(int j = 0; j < 26; j++) {
			int p = upper_bound(pos[j].begin(),pos[j].end(),last) - pos[j].begin();
			p --;
			int cur = pos[j][p];
			cout << " j = " << j << " p = " << p << endl;
			cout << "cur = " << cur << endl;
			cout << "start = " << start << endl;
			if(p >= 0 && cur >= start) {
				str += s[cur];
				cout << "str = " << str << endl;
				i = cur;
				break;
			} 
		}
	}
	sort(str.begin(), str.end());
	cout << str << endl;
	return 0;
}