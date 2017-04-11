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

const int maxn =  105;
int a[maxn],n,m,k;

int main()
{
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int cnt = 1;
	while(1) {
		// cout << "m = " << m << " cnt = " << cnt << endl;
		if(m+cnt <= n) {
			if(a[(m+cnt)] != 0 && a[(m+cnt)] <= k) {
				cout << 10*cnt << endl;
				return 0;
			}
				
		}	
		if(m-cnt > 0) {
			if(a[(m-cnt)] != 0 && a[(m-cnt)] <= k) {
				cout << 10*cnt << endl;
				return 0;
			}
		}
		cnt++;
	}	
	return 0;
}