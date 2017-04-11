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
	LL n;
	cin >> n;
	for(LL i = 1; i <= n; i++) {
		if(i == 1) cout << 2 << endl;
		else{
			LL ans = i*(i+1)*(i+1) - i + 1;
			cout << ans << endl;
		}
	}
	return 0;
}