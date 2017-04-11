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

string s;
int a[4];

int main()
{
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	cin >> s;
	int len = s.length();
	if(len % 2 == 1) cout << -1 << endl;
	else {
		for(int i = 0; i < len; i++) {
			if(s[i] == 'U') a[0]++;
			if(s[i] == 'D') a[1]++;
			if(s[i] == 'L') a[2]++;
			if(s[i] == 'R') a[3]++;
		}
		int ans = abs(a[0]-a[1])/2;
		ans += abs(a[2]-a[3])/2;
		if(abs(a[0]-a[1]) % 2 == 1) ans++;
		cout << ans << endl;
	}
	return 0;
}