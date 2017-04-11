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

const int maxn = (1e5)+10;

LL a[3];

int main()
{
	cin >> a[0] >> a[1] >> a[2];
	sort(a,a+3);
	a[1] = a[1] - a[0];
	a[2] = a[2] - a[0];
	a[0] = 0;
	LL miss = 0;
	if(a[1] == a[2]) {
		if(a[1] == 0 || a[1] == 1) miss = 0;
		else miss = a[1]-1;
	}
	else if(a[1] + 1 == a[2]) {
		miss = a[1];
	}
	else {
		miss = a[2] - 1 - a[1];
		miss += (a[2]-1);
	}
	cout << miss << endl;
	return 0;
}