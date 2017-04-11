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

string s;
int a[maxn];
int n;

int main()
{
	cin >> n >> s;
	memset(a, 0, sizeof(a));
	if(s[0] == '<') {
		a[0] = 1;
		int i = 0;
		while(i < n) {
			i++;
			if(s[i] == '<') a[i] = 1;
			else break;
		}
	}
	if(s[n-1] == '>') {
		a[n-1] = 1;
		int i = n-1;
		while(i >= 0) {
			i--;
			if(s[i] == '>') a[i] = 1;
			else break;
		}
	}
	int cnt = 0;
	for(int i = 0; i < n; i++)
		if(a[i] == 1) cnt++;
	cout << cnt << endl;
	return 0;
}