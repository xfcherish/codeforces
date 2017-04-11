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
int n;
int main()
{
	int odd_r = 0;
	int odd_b = 0;
	int even_r = 0;
	int even_b = 0;
	cin >> n >> s;
	int len = s.length();
	for(int i = 0; i < len; i++) {
		if(i % 2 == 0) {
			if(s[i] == 'r') even_r++;
			else even_b++;
		}
		else {
			if(s[i] == 'r') odd_r++;
			else odd_b++;
		}
	}
	int ans1,ans2;
	// even --- b , odd --- r
	ans1 = max(even_r, odd_b);
	// even --- r , odd --- b
	ans2 = max(even_b,odd_r);
	int ans = min(ans1, ans2);
	cout << ans << endl;
	return 0;
}