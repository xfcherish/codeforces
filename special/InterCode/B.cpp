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

const int maxn = (100)+10;

int n,p[maxn],total[maxn];

bool judge(char c) {
	if(c == 'a' || c == 'e'
	|| c== 'i' || c == 'o'
	|| c == 'u' || c == 'y')
		return true;
	return false;
}
bool solve() {
	for(int i = 1; i <= n; i++) {
		//cout << "total[" << i << "]=" << total[i] << endl;
		if(p[i] != total[i]) 
			return false;
	}
	return true;
}

int main()
{
	cin >> n;
	string s;
	for(int i = 1; i <= n; i++)
		cin >> p[i];
	scanf("\n");
	memset(total, 0, sizeof(total));
	for(int i = 1; i <= n; i++) {
		getline(cin,s);
		for(int j = 0; j < s.length(); j++) {
			if(judge(s[j]))
				total[i]++;
		}
	}
	if(solve()) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}