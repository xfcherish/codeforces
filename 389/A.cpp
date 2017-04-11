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

int n,m,k;
int main()
{
	int n1,m1;
	cin >> n >> m >> k;
	while((n1-1)*2*m < k) n1++;
	n1--;
	while((n1-1)*2*m + (m1)*2 < k) m1++;
	if(k % 2 == 1) {
		cout << n1 << " " << m1 << " L" << endl;
	}
	else {
		cout << n1 << " " << m1 << " R" << endl;
	}
	return 0;
}