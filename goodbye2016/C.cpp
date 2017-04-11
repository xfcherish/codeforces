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

int n;
int c[maxn],d[maxn],s[maxn];

int main()
{
	int start = 10000000;
	cin >> n;
	bool inf = true;
	s[0] = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &c[i],&d[i]);
		if(d[i] == 2) inf = false;
		s[i] = s[i-1]+c[i];
	}
	if(inf == true) cout << "Infinity" << endl;
	else {
		for(int i = 1; i <= n; i++) {
			if(d[i] == 2) {
				start = min(1899-s[i-1],start);
			}	
		}
		for(int i = 1; i <= n; i++) {
			if(d[i] == 1) {
				if(start + s[i-1] < 1900) {
					cout << "Impossible" << endl;
					return 0;
				}
			}
		}	
		int last = start + s[n];
		// cout << "start = " << start << endl;
		cout << last << endl;
	}
	return 0;
}