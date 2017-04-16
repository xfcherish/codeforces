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
int n;
int main()
{
	cin >> n >> s;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == '<') cnt++;
		else break;
	}
	for(int i = n-1; i >= 0; i--) {
		if(s[i] == '>') cnt++;
		else break;
	}
	cout << cnt << endl;
	return 0;
}