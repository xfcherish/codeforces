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

int n,c;
int a[maxn];
int main()
{
	cin >> n >> c;
	for(int i = 1 ; i <= n; i++)
		cin >> a[i];
	int ans = 1;
	for(int i = 2; i <= n; i++) {
		if(a[i] - a[i-1] <= c)
			ans++;
		else ans = 1;
	}
	cout << ans << endl;
	return 0;
}