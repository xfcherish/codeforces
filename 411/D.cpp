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

typedef long long ll;
typedef pair<int,int> PII;

const int maxn =  (1e5)+10;
const int mod = (1e9)+7;

string s;
int main()
{
	cin >> s;
	int len = s.length();
	ll cnt = 0;
	ll ans = 0;
	for(int i = len-1;  i >= 0; i--) {
		if(s[i] == 'b') {
			cnt++;
		}
		else {
			ans = (ans + cnt) % mod;
			cnt = (cnt * 2) % mod;
		}
	}
	cout << ans << endl;
	return 0;
}