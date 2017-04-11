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
int a[maxn];
int n;

bool judge() {
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] == 1) return 0;
	}
	return 1;
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] % 2 == 1) a[i] = 1;
		else {
			if(a[i] >= 2) a[i] = 2;
			else a[i] = 0;
		}
	}
	for(int i = 1; i < n; i++) {
		if(a[i] == 1 && a[i+1] == 1) {
			a[i] = a[i+1] = 0;
		}
	}
	for(int i = 1; i+2 <= n; i++) {
		if(a[i] == 1 && a[i+1] == 2 && a[i+2] == 1) {
			a[i] = a[i+1] = a[i+2] = 0;
		}
	}
	if(judge()) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}