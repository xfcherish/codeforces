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
int r[maxn],l[maxn];
int suml,sumr;
int n;

int main()
{
	cin >> n;
	suml = sumr = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d%d",&l[i],&r[i]);
		suml += l[i];
		sumr += r[i];
	}
	int max_d = abs(suml - sumr);
	int k = 0;
	for(int i = 1; i <= n; i++) {
		int new_r = sumr - r[i] + l[i];
		int new_l = suml - l[i] + r[i];
		int new_d = abs(new_l - new_r);
		if(new_d > max_d) {
			k = i;
			max_d = new_d;
		}
	}
	cout << k << endl;
	return 0;
}