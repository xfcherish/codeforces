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

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = (2e5)+10;

int n,k;
int a[maxn];

int main()
{
	cin >> n >> k;
	int min_a = (1e9)+10;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		min_a = min(min_a, a[i]);
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		int d = a[i] - min_a;
		if(d % k != 0) {
			cout << -1 << endl;
			return 0;
		}
		else {
			ans = ans + d/k;
		}
	}
	cout << ans << endl;
	return 0;
}