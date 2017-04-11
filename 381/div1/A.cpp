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

int main()
{
	int n,m,l,r,k;
	cin >> n >> m;
	k = 1000000000;
	for(int i = 1; i <= m; i++) {
		scanf("%d%d",&l,&r);
		k = min(k, r-l+1);
	}
	cout << k << endl;
	for(int i = 1; i <= n; i++)
		cout << (i%k) << " ";
	cout << endl;
	return 0;
}