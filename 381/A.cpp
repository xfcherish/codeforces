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

long long n,a,b,c;
int main()
{
	cin >> n >> a >> b >> c;
	if(n % 4 == 0) {
		cout << 0 << endl;
	}
	else if(n % 4 == 3) {
		long long ans = min(a,b+c);
		ans = min(ans, 3*c);
		cout << ans << endl;
	}
	else if(n % 4 == 2) {
		long long ans = min(2*a,b);
		ans = min(ans, 2*c);
		cout << ans << endl;
	}
	else if(n % 4 == 1) {
		long long ans = min(3*a,a+b);
		ans = min(ans, c);
		cout << ans << endl;
	}
	return 0;
}