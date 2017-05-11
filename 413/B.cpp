#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>

using namespace std;

# define pb push_back
# define mp make_pair

typedef long long ll;
typedef pair<int,int> PII;

const int maxn =  (2e5)+10;

set<PII> s[4];
int p[maxn],a[maxn],b[maxn];

int main()
{
	// freopen("input.txt","r",stdin);
	int c,n,m;
	cin >> n;
	for(int i = 1; i <= n; i++) 
		scanf("%d", &p[i]);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		if(a[i] == b[i]) {
			s[a[i]].insert(mp(p[i],i));
		}
		else {
			s[a[i]].insert(mp(p[i],i));
			s[b[i]].insert(mp(p[i],i));
		}
	}
	cin >> m;
	for(int i = 1; i <= m; i++) {
		cin >> c;
		// cout << "i = " << i << endl;
		// cout << "c = " << c << endl;
		// cout << "size = " << s[c].size() << endl;
		if(s[c].empty()) 
			cout << -1 << " ";
		else {
			set<PII>::iterator it = s[c].begin();
			cout << it->first << " ";
			int order = it->second;
			int c2 = a[order] + b[order] - c;
			// cout << "c2 = " << c2 << endl;
			if(c2 == c) {
				s[c].erase(it);
			}
			else {
				// cout << "p[order] = " << p[order] << endl;
				set<PII>::iterator it2 = s[c2].find(mp(p[order],order));
				// if(it2 != s[c2].end())
					s[c2].erase(it2);
				// else cout << "hi" << endl;
				s[c].erase(it);
			}
		} 
		// cout << "size2 = " << s[c].size() << endl;
	}
	cout << endl;
	return 0;
}