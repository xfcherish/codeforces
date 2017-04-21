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

int gcd(int a, int b) {
	return ( b == 0 ? a : gcd(b, a % b));
}

int num[maxn],n;

int ngcd(int i, int j) {
	if(i+1  == j) return gcd(num[i], num[j]);
	return gcd(num[i], ngcd(i+1,n));
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> num[i];
	int d = ngcd(1,n);
	// cout << " d = " << d << endl;
	cout << "YES" << endl;
	if(d > 1) cout << 0 << endl;
	else {
		int ans = 0;
		for(int i = 1; i <= n; ) {
			int cnt = 0;
			while(num[i] % 2 == 1) {
				cnt++;
				i++;
			}
			if(cnt % 2 == 0)  ans = ans + cnt/2;
			else ans = ans + cnt/2 + 2;
			i++;
		}
		cout << ans << endl;
	}
	return 0;
}