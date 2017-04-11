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

const int maxn = (2000)+10;

int n,m;
int a[maxn];
int p[maxn];
int main()
{
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	int i;
	int min_max = 0;
	cin >> n >> m;
	memset(p, 0 , sizeof(p));
	for(i = 1; i <= n; i++)  {
		cin >> a[i];
		if(a[i] <= m) {
			p[a[i]]++;
		}
	}
	min_max = n/m;
	int change = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] > m) {
			int min_p = 10000;
			int pos_j = -1;
			for(int j = 1; j <= m; j++) {
				if(min_p > p[j]) {
					min_p = p[j];
					pos_j = j;
				}
			}
			if(p[pos_j] < min_max) {
				a[i] = pos_j;
				change++;
				p[pos_j]++;
			}
		}
		// if(a[i] > m) {
		// 	a[i] = 1;
		// 	p[1]++;
		// 	change++;
		// }
		//cout << "now a[" << i << "]=" << a[i] << endl;
	}
	for(int cur = 1; cur <= m; cur++) {
		while(p[cur] < min_max) {
			for(int j = 1; j <= n; j++) {
				int cur2 = a[j];
				if(p[cur2] > min_max) {
					a[j] = cur;
					p[cur2]--;
					p[cur]++;
					change++;
					break;
				}
			}
		}
		//cout << "a[" << i << "]=" << a[i] << endl;
	}
	cout << min_max << " " << change << endl;
	for(int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}