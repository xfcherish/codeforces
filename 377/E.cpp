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

int p[maxn],s[maxn];
vector<int> plink[maxn];
set<int> pset;
int n,m;
	
int main()
{
	// freopen("input.txt","r",stdin);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
		pset.insert(p[i]);
	}
	sort(p+1,p+1+n);
	for(int i = 1; i <= m; i++) {
		scanf("%d", &s[i]);
		int tmp = s[i];
		while(tmp >= p[1]) {
			if(pset.find())
		}
	}
	return 0;
}