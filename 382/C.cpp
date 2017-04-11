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
	long long n,k;
	cin >> n;
	n = 2*(n-2);
	k = (1+(long long)sqrt(1+4*n))/2;
	k = k - 1;
	while(1) {
		long long n1 = k*(k-1);
		long long n2 = k*(k+1);
		if(n1 <= n && n2 > n) break;
		k++;
	}
	cout << k << endl;
	return 0;
}