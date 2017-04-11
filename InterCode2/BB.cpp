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

int a[25][25],n,m;

bool judge() {
	for(int i = 1; i <= n; i++) {
		int cnt = 0;
		for(int j = 1; j <= m; j++) {
			if(a[i][j] != j) cnt++;
		}
		if(cnt > 2) return false;
	}
	return true;
}

int main()
{
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	int i,j;
	cin >> n >> m;
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	if(judge()) {
		cout << "YES" << endl;
		return 0;
	}
	for(i = 1; i <= m; i++) {
		for(j = i+1; j <= m; j++) {
			for(int k = 1; k <= n; k++) {
				swap(a[k][i],a[k][j]);
			}
			if(judge()) {
				cout << "YES" << endl;
				return 0;
			}
			for(int k = 1; k <= n; k++) {
				swap(a[k][i],a[k][j]);
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}