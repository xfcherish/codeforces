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

int a[maxn],b[maxn],c[maxn];
int n,x;

int main()
{
	freopen("test.txt","r",stdin);
	cin >> n >> x;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i]^x;
		c[a[i]]++;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int tmp = a[i]^x;
		if(tmp != a[i])
			ans += c[tmp];
		else ans += (c[tmp]-1);
	}
	cout << ans/2 << endl;
	return 0;
}