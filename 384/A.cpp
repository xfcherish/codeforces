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

int n,a,b;
string s;

int main()
{
	cin >> n >> a >> b >> s;
	a--;
	b--;
	if(s[a] == s[b]) 
		cout << 0 << endl;
	else cout << 1 << endl;
	return 0;
}