#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>

using namespace std;

# define pb push_back
# define mp make_pair

typedef long long LL;
typedef pair<int,int> PII;

const int maxn =  200010;

int n,k;
int a[maxn];


int main()
{
	cin >> n >> k;
	int res = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		res += (a[i]/(2*k));
		a[i] %= (2*k);
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] > k) cnt += 2;
		else cnt += 1;
	}
	if(cnt % 2 == 1) res = res + (cnt/2) + 1;
	else res = res + cnt/2;
	cout << res << endl;

	return 0;
}