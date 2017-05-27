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

typedef unsigned long long ll;
typedef pair<int,int> PII;

const int maxn =  (3e5)+10;
const int mod = (1e9)+7;

int n;
ll x[maxn], two[maxn];

int main()
{
	cin >> n;
	two[0] = 1;
	for(int i = 1; i <= n; i++) {
		cin >> x[i];
		two[i] = (two[i-1]*2) % mod;
	}
	sort(x+1, x+1+n);
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		ll num1 = two[i-1]-1;
		ll num2 = two[n-i]-1;
		ll num = (num1 - num2 + mod) % mod;
		ll add =  num * x[i] % mod;
		ans = (ans + add) % mod;
	}
	cout << ans << endl;
	return 0;
}