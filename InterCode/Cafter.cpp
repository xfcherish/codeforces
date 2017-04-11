#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
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
int a[maxn];
LL sum[maxn];

set<PII> good;
multiset<LL> segsum;

typedef set<pair<int,int> >:: iterator iter;

int main()
{
	int n,x;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
	}
	good.insert(make_pair(1,n));
	segsum.insert(sum[n]);
	for(int i = 1; i <= n; i++) { 
		cin >> x;
		iter seg = good.upper_bound(make_pair(x,0));
		if(seg == good.end()) seg--;
		if(seg->first > x) seg--;
		int l = seg->first;
		int r = seg->second;
		good.erase(seg);
		segsum.erase(segsum.find(sum[r]-sum[l-1]));
		if(x-1 >= l) {
			good.insert(make_pair(l,x-1));
			segsum.insert(sum[x-1]-sum[l-1]);
		}
		if(r >= x+1) {
			good.insert(make_pair(x+1,r));
			segsum.insert(sum[r]-sum[x]);
		}
		if(segsum.empty()) 
			cout << 0 << endl;
		else cout << *(segsum.rbegin()) << endl;
	}	
	return 0;
}