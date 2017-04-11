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

int k,r;
int main()
{
	cin >> k >> r;
	int cnt = 1;
	while(1) {
		if(k*cnt % 10 == 0 || k*cnt % 10 == r) {
			break;
		}
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}