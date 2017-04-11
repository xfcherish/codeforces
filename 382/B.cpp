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

int n,n1,n2;
int a[maxn];

int main()
{
	cin >> n >> n1 >> n2;
	double ans1 = 0;
	double ans2 = 0;
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a+1, a+1+n);
	if(n1 > n2) swap(n1,n2);
	for(int i = n; i > n-n1; i--) {
		ans1 = ans1 + a[i];
	}
	ans1 /= n1;
	for(int i = n-n1; i > n-n1-n2; i--) {
		ans2 = ans2 + a[i];
	}
	ans2 /= n2;
	double ans = ans1 + ans2;
	printf("%.7lf\n",ans);
	return 0;
}