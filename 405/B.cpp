#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

# define pb push_back
# define mp make_pair

typedef long long LL;
typedef pair<int,int> PII;

const int maxn =  2000010;

int n,m;
vector<int> f[maxn];
long long val[maxn];

int main()
{
	int l,r;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		val[i] = i;
	}
	for(int i = 1; i <= m; i++) {
		scanf("%d%d",&l,&r);
		f[l].push_back(r);
		f[r].push_back(l);
		val[l] += r;
		val[r] += l;
	}
	for(int i = 1; i <= n; i++) {
		int len = f[i].size();
		if(len != 0) {
			for(int k = 0; k < len; k++) {
				int j = f[i][k];
				if(f[j].size() != len || val[j] != val[i]) {
					cout << "NO" << endl;
					return 0;
				}
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}