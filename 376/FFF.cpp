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

int sum[maxn];
int n;

int main()
{
	int tmp,max_val;
	cin >> n;
	max_val = 0;
	for(int i = 1; i <= n; i++) {
		cin >> tmp;
		sum[tmp]++;
		max_val = max(max_val, tmp);
	}
	for(int i = 1; i <= max_val; i++)
		sum[i] += sum[i-1];
	LL ans = 0;
	for(int i = 1; i <= max_val; i++) {
		if(sum[i] - sum[i-1] > 0) {
			//cout << " i = " << i << endl;
			LL tmp_ans = 0;
			for(int j = i; j <= max_val; j += i) {
				int l = j;
				int r = min(j+i-1, max_val);
				tmp_ans += (sum[r]-sum[l-1])*(long long)(j);
				// cout << "l =  " << l << "  r = " << r << endl;
				// cout << "add = " << (sum[r]-sum[l-1])*(long long)(i) << endl;
			}
			//cout << " tmp_ans = " << tmp_ans << endl;
			ans = max(tmp_ans, ans);
		}
	}
	cout << ans << endl;
	return 0;
}