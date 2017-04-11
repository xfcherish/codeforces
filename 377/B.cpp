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

const int maxn = (500)+10;

int n,k;
int a[maxn];

int main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int cnt = 0;
	for(int i = 2; i <= n; i++) {
		if(a[i]+a[i-1] >= k) continue;
		else {
			int add =  (k-a[i]-a[i-1]);
			a[i] += add;
			cnt += add;
		}
	}
	cout << cnt << endl;
	for(int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}