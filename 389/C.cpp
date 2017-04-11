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
string s;
vector<PII> v;

bool dd(int i1, int i2) {
	int d1 = i1 - i2;
	int x1 = v[i1].first;
	int y1 = v[i1].second;
	int x2 = v[i2].first;
	int y2 = v[i2].second;
	int d2 = abs(x1-x2)+abs(y1-y2);
	if(d1 == d2) return true;
	return false;
}

int main()
{
	cin >> n >> s;
	int x,y,last_i;
	x = y = 0;
	v.push_back(make_pair(x,y));
	for(int i = 0; i < n; i++) {
		if(s[i] == 'U') y++;
		else if(s[i] == 'D') y--;
		else if(s[i] == 'L') x--;
		else if(s[i] == 'R') x++;
		v.push_back(make_pair(x,y));
	}	
	int len = v.size();
	int pre = 0;
	int cnt = 0;
	last_i = 0;
	// cout << "len = " << len << endl;
	for(int i = 0; i < len;  ) {
		while(i < len && dd(i,last_i) == true) i++;
		i--;
		last_i = i;
		// cout << "last_i = " << last_i << endl;
		cnt++;
		if(last_i >= len-1) break;
	}
	cout << cnt << endl;
	return 0;
}