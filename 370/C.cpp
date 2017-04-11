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


int main()
{
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	int num,x,y;
	int a[3];
	cin >> x >> y;
	num = 0;
	a[0] = a[1] = a[2] = y;
	while(1) {
		if(a[0] == x && a[1] == x && a[2] == x) break;
		sort(a,a+3);;
		if(a[1] + a[2] > x) {
			a[0] = x;
			num++;
		}
		else {
			a[0] = a[1] + a[2] - 1;
			num++;
		}
	}
	cout << num << endl;
	return 0;
}