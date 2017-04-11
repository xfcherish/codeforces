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
	int n;
	cin >> n;
	int ans = 0;
	if(n == 0) 
		ans = 1;
	else if(n % 4 == 0) 
		ans = 6;
	else if(n % 4 == 1)
		ans = 8;
	else if(n % 4 == 2)
		ans = 4;
	else if(n % 4 == 3)
		ans = 2;
	cout << ans << endl;
	return 0;
}