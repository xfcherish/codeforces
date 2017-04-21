#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <string>

using namespace std;

# define pb push_back
# define mp make_pair

typedef long long ll;
typedef pair<int,int> PII;

const int maxn = 100;
const int inf = (1e9)+10;

int move(string s1, string s2) {
	int cnt = 0;
	for(int i = 0; i < s1.length(); i++) {
		if(s1 == s2) return cnt;
		rotate(s1.begin(), s1.begin() + 1, s1.end());
		cnt++;
	}
	return -1;
}

int main()
{
	vector<string> str;
	string tmp;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> tmp;
		str.push_back(tmp);
	}
	int ans = inf;
	for(int i = 0; i < n; i++) {
		string m = str[i];
		int cur = 0;
		for(int j = 0; j < n; j++) {
			int cnt = move(str[j], m);
			if(cnt == -1) {
				cur = inf;
				break;
			}
			else cur += cnt;
		}
		ans = min(ans, cur);
	}
	if(ans == inf) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}