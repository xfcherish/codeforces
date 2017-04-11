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

int solve(int n, LL k) {
	if(n == 1) return 1;
	LL mid =  (1LL<<(n-1));
	// cout << "n = " << n << " mid = " << mid << " k = " << k << endl;
	if(k == mid)
		return n;
	if(k > mid) 
		return solve(n-1, k-mid);
	if(k < mid) 
		return solve(n-1, k);
}

int main()
{
	int n;
	LL k;
	cin >> n >> k;
	cout << solve(n,k) << endl;	
	return 0;
}