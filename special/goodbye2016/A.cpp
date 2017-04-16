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

int n,k;

int main()
{
	cin >> n >> k;
	int r = 240 - k;
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(r >= 5*i ) {
			r -= 5*i;
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}