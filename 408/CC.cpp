#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

# define pb push_back
# define mp make_pair

typedef long long LL;
typedef pair<int,int> PII;

const int maxn =  300010;
const int inf = 1000000000;
int a[maxn],n,cnt;
vector<int> child[maxn];
multiset<int> se;

int main()
{
	int u,v,cur,ans;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		se.insert(a[i]);
	}
	for(int i = 1; i < n; i++) {
		scanf("%d%d",&u,&v);
		child[u].push_back(v);
		child[v].push_back(u);
	}
	ans = inf+10;
	for(int i = 1; i <= n; i++) {
		cur = a[i];
		multiset<int>::iterator it = se.find(a[i]);
		se.erase(it);
		for(int j = 0; j < child[i].size(); j++) {
			cur = max(cur, a[child[i][j]] + 1);
			it = se.find(a[child[i][j]]);
			se.erase(it);
		}
		if(!se.empty())
			cur = max(cur, *se.rbegin() + 2);
		ans = min(cur, ans);
		se.insert(a[i]);
		for(int j = 0; j < child[i].size(); j++) 
			se.insert(a[child[i][j]]);
	}
	cout << ans << endl;
	return 0;
}