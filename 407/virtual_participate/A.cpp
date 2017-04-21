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

const int maxn =  200010;

int main()
{
	int n,k,tmp;
	int ans = 0,cnt = 0;
	cin >> n >> k;	
	for(int i = 1; i <= n; i++) {
		cin >> tmp;
		ans += (tmp/(2*k));
		tmp %= (2*k);
		if(tmp > k) cnt += 2 ;
		else if(tmp > 0) cnt += 1;
	}
	if(cnt % 2 == 0) ans += (cnt / 2);
	else ans = ans + (cnt/2) + 1;
	cout << ans << endl;
	return 0;
}