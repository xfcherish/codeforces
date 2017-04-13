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

int n,x,y,ans;
long long fact[maxn];
string s;

void init() {
	fact[0] = 1;
	for(int i = 1; i <= 200000; i++) 
		fact[i] = (fact[i-1] * i) % mod;
}

long long pow_mod(long long a, long long b) {
	if(b == 0) return 1;
	long long temp = pow_mod(a, b>>1);
	temp = temp * temp % mod;
	if(b & 1) temp = temp * a % mod;
	return temp;
}

long long C(int x,int y) {
	long long ans = fact[x];
	ans = ans * pow_mod(fact[y],mod-2) % mod;
	ans = ans * pow_mod(fact[x-y],mod-2) % mod;
	return ans;
}
int main()
{
	init();
	cin >> s;
	x = y = 0;
	ans = 0;
	for(int i = 0; i < s.length(); i++) 
		if(s[i] == ')') y++;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == '(') x++;
		else {
			if(x != 0 )
				ans = (ans + C(x+y-1,y)) % mod;
			// cout << "ans = " << ans << endl;
			y--;
		}
	}
	cout << ans << endl;
	return 0;
}