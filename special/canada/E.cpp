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


int n,m,c,u;
int a[maxn],b[maxn];
int p[maxn], s[maxn];
map<int,queue<int> > v2s;

int main()
{
	scanf("%d%d",&n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &p[i]);
	for(int i = 1; i <= m; i++) {
		scanf("%d", &s[i]);
		v2s[s[i]].push(i);
	}
	sort(p+1,p+1+n);
	sort(s+1,s+1+m); 
	for(int i = 1; i <= n; i++) {
		int x = p[i];
		int cost = 0;
		while(x < )
	}	
	return 0;
}