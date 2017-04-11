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
const int mod = (1e9)+7;

int n;
int l[maxn],dp[maxn];
string s;


int main()
{
	cin >> s;
	n = s.length();
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == '(') l[i+1] = l[i]+1;
		else l[i+1] = l[i]; 
	}
	int all = 0;
	int pre = 0;
	for(int i = 1; i <= n; i++) {
		if(s[i-1] == ')') {
			dp[i] = (l[i]-l[pre] +  all) % mod;
			all = (all + dp[i]) % mod;
			pre = i;
		}
	}
	for(int i = 1; i <= n; i++) {
		cout << "dp[" << i << "]=" << dp[i] << endl;
	}
	cout << all << endl;
	return 0;
}