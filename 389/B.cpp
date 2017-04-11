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

string s1,s2;
int a[26];

int main()
{
	cin >> s1 >> s2;
	int n = s1.length();
	memset(a,-1,sizeof(a));
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		int c1 = s1[i]-'a';
		int c2 = s2[i]-'a';
		if(c1 == c2) continue;
		if(a[c1] == -1) {
			a[c1] = c2;
			cnt++;
		}
		else if(a[c1] != c2) {
			cout << "-1" << endl;
			return 0;
		}
		if(a[c2] == -1) {
			a[c2] = c1;
		}
		else if(a[c2] != c1) {
			cout << "-1" << endl;
			return 0;
		}
	}
	cout << cnt << endl;
	bool vis[30];
	memset(vis, 0 ,sizeof(vis));
	for(int i = 0; i < 26; i++) {
		char c1 = 'a'+i;
		char c2 = 'a'+a[i];
		// cout << "i = " << i << " "  << c1 << " " << c2 << endl;
		if(a[i] == -1) continue;
		if(c1 != c2) {
			if(vis[i] == 0 && vis[a[i]] == 0)
			cout << c1 << " " << c2 << endl;
			vis[i] = vis[a[i]] = 1;
		}
		
	}
	return 0;
}