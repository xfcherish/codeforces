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

bool judge(int pos) {
	int vis[26];
	int cnt = 0;
	memset(vis,0,sizeof(vis));
	for(int i = pos; i < pos + 26 ; i++) {
		if(s[i] == '?') cnt++;
		else{ 
			vis[s[i]-'A']++;
		}
	}
	for(int i = 0; i < 26; i++) {
		if(vis[i] > 1) return false;
	}
	for(int i = pos; i < pos + 26; i++) {
		if(s[i] == '?') {
			for(int j = 0; j < 26; j++) {
				if(vis[j] == 0) {
					s[i] = (char)('A'+j);
					vis[j] = 1;
					break;
				}
			}
		}
	}
	return true;
}

int main()
{
	cin >> s;
	int len = s.length();
	for(int i = 0; i + 25 < len; i++) {
		if(judge(i)) {
		//	cout << "s = " << s << endl;
			for(int j = 0; j < len; j++) {
				if(s[j] == '?') s[j] = 'A';
				cout << s[j];
			}
			cout << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}