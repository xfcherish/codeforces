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

int n,k,l,m;
int p[maxn];
vector<int> person[maxn];


struct cmp {
	bool operator() (const int & a, const int & b){
		return p[a] > p[b];
	}
	/* data */
};

set<int,cmp> s,s2;

int main()
{
	// freopen("input.txt","r",stdin);
	int a,b;
	cin >> n;
	memset(p, -1, sizeof(p));
	for(int i = 1; i <= n; i++) {
		scanf("%d%d",&a,&b);
		p[a] = max(p[a], b);
		person[a].push_back(b);
	}
	for(int i = 1; i <= n; i++) {
		if(p[i] != -1)
			s.insert(i);
	}
	cin >> k;
	for(int i = 1; i <= k; i++) {
		cin >> l;
		// cout << "s size = " << s.size() << endl;
		// for(it = s.begin(); it != s.end(); it++) {
		// 	cout << it->first << " " << it->second << endl;
		// }
		s2 = s;
		for(int j = 1; j <= l; j++) {
			scanf("%d", &a);
			// cout << "a = " << a << " p[a] = " << p[a] << endl; 
			set<int,cmp>::iterator it = s2.find(a);
			if(it != s2.end())
				s2.erase(it);
		}
		// cout << "size = " << s.size() << endl;
		if(s2.empty()) cout << "0 0" << endl;
		else {
			set<int,cmp>::iterator it = s2.begin();
			set<int,cmp>::iterator it2 = it;
			it2++;
			if(it2 == s2.end()) {
				int i = (*it);
				cout << i << " " << person[i][0] << endl;
			}
			else {
				int max_other = p[*it2];
				// cout << "max_other = " << max_other << endl;
				int i = (*it);
				int ans = *(lower_bound(person[i].begin(), person[i].end(), max_other));
				cout << i << " " << ans << endl;
			}
		}	
	}
	return 0;
}