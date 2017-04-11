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

int n,d;
string dir;

int main()
{
	// freopen("bigdata.txt","r",stdin);
	int s  = 0;
	cin >> n;
	bool tag = true;
	for(int i = 0; i < n; i++) {
		cin >> d >> dir;
		if(s > 20000 || s < 0) {
			tag = false;
		}
		if(s == 20000) {
			if(dir != "North") {
				tag = false;
			}
		}
		if(s == 0) {
			if(dir != "South") {
				tag = false;
			}
		}
		if(dir == "North") {
			s -= d;
		}
		else if(dir == "South") {
			s += d;
		}
	}
	if(s != 0) tag = false;
	if(tag) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}