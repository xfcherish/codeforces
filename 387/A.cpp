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
	int n,a,b,s;
	cin >> n;
	int cur_s = 10000000;
	int ans_a,ans_b;
	for(int a = 1;  a*a <= n; a++) {
		if(n % a == 0) {
			b = n/a;
			s = b - a;
			if(b < a ) continue;
			if(s < cur_s) {
				s = cur_s;
				ans_a = a;
				ans_b = b;	
			}
		}
	}
	cout << ans_a << " " << ans_b << endl;
	return 0;
}