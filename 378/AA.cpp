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

string s;
char vow[6] = {'A','E','I','O','U','Y'};
bool judge(char c) {
	for(int i = 0; i < 6; i++) {
		if(c == vow[i]) return 1;
	}
	return 0;
}
int main()
{
	cin >> s;
	s = 'A' + s + 'A';
	int ans = 1;
	int last = 0;
	for(int i = 0; i < s.length(); i++) {
		if(judge(s[i])) {
			ans = max(ans,i-last);
			last = i;
		}
	}
	cout << ans << endl;
	return 0;
}