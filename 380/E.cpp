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
int a[maxn],n,s;
int num[maxn],null[maxn],sum[maxn];

int main()
{
	cin >> n >> s;
	int error = 0;
	int max_num = 0;
	int tag = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d",&a[i]);
		if(i == s) {
			if(a[i] != 0) tag++;
			a[i] = 0;
			num[0]++ ;
		}
		else {
			if(a[i] == 0) error++;
			else {
				num[a[i]]++;
				max_num = max(max_num, a[i]);
			}
		}
	}
	sum[0] = 1;
	for(int i = 1; i <= max_num; i++) {
		if(num[i] == 0) 
			null[i] = null[i-1]+1;
		else null[i] = null[i-1];
		sum[i] = sum[i-1] + num[i];
	}
	int ans = 100000000;
	if(max_num == 0) {
		cout << error + tag << endl;
		return 0;
	}
	for(int i = 1; i <= max_num; i++) {
		int res = sum[max_num] - sum[i];
		int temp =  max(res, null[i]-error);
		// cout << "i = " << i << " res = " << res << " null = " << null[i] 
		// 	<< " error = " << error << endl;
		ans = min(ans, temp+tag+error);
		// cout << "i = " << i << " temp = " << temp + tag << endl;
	}
	cout << ans << endl;
	return 0;
}