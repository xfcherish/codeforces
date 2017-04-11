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

int x[10],y[10];
set<PII> s;

int main()
{
	int nx,ny;
	for(int i = 0; i < 3; i++) {
		cin >> x[i] >> y[i];
	}
	for(int i = 0 ; i < 3; i++) {
		nx = x[i % 3] + x[(i+1) % 3] - x[(i+2)%3];
		ny = y[i % 3] + y[(i+1) % 3] - y[(i+2)%3];
		s.insert(make_pair(nx,ny));
	}
	cout << s.size() << endl;
	set<PII>::iterator it;
	for(it = s.begin(); it != s.end(); it++) {
		cout << (it)->first << " " << (it)->second << endl;
	}
	return 0;
}