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

string s;
int n,k,min_p,max_p;
bool judge() {
	int d = max_p - min_p;
	if(d % k != 0) return false;
	for(int i = min_p; i <= max_p; i+= k) {
		if(s[i] == '#') return false;
	}
	return true;
}

int main()
{
	cin >> n >> k >> s;
	int gp,tp;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'G') gp = i;
		if(s[i] == 'T') tp = i;
	}
	min_p = min(gp,tp);
	max_p = max(gp,tp);
	if(judge()) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}