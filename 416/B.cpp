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

using namespace std;

# define pb push_back
# define mp make_pair

typedef long long ll;
typedef pair<int,int> PII;

const int maxn =  (2e5)+10;

int p[maxn];

int main()
{
	int n,m,l,r,x;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		scanf("%d",&p[i]);
	for(int i = 1; i <= m; i++) {
		scanf("%d%d%d",&l,&r,&x);
		int cnt = 0;
		for(int j = l; j <= r; j++) {
			if(p[j] < p[x]) {
				cnt ++ ;
			}
		}
		int pos = l + cnt;
		if(pos == x) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}