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

int main()
{
	int x,y,z,n;
	cin >> n;
	if(n == 1) {
		cout << -1 << endl;
		return 0;
	}
	x = n;
	y = n+1;
	z = n*(n+1);
	cout << x << " " << y << " " << z << endl;
	return 0;
}