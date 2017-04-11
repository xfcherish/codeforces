#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

const int maxn = (1e6)+10;
int a[maxn],b[maxn],all[maxn],n;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int i,m,l,r,ans;
	cin >> n;
	b[0] = 0;
	all[0] = 0;
	set<int> s;
	for(i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		b[i] = b[i-1]^a[i];
		if(s.find(a[i]) == s.end()) {
			all[i] = all[i-1]^a[i];
			s.insert(a[i]);
		}
		else {
			all[i] = all[i-1];
		}
	}
	cin >> m;
	for(i = 1; i <= m; i++) {
		scanf("%d%d",&l,&r);
		cout << "all = " << (all[r]^all[l-1])<< endl;
		cout << "b = " << (b[r]^b[l-1]) << endl;
		ans = all[r]^all[l-1];
		ans = ans^b[r];
		ans = ans^b[l-1];
		cout << ans << endl;
	}
	return 0;
}