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

LL n;
long long tran(char c) {
	if(c == 'f' ) return 1;
	if(c == 'e') return 2;
	if(c == 'd') return 3;
	if(c == 'a') return 4;
	if(c == 'b') return 5;
	if(c == 'c') return 6;
	return 0;
}
int main()
{
	char c;
	cin >> n >> c;
	//cout << "n  = " << n << " c = " << c << endl;
	n = n - 1;
	LL ans = 0;
	ans = (n/4)*(12+4);
	n = n % 4;
	if(n == 1 || n == 3)
		ans += (6+1);
	ans += tran(c);
	cout << ans << endl;	
	return 0;
}