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
	int n;
	string s;
	cin >> n >> s;
	int cnt = 0;
	vector<int> ans;
	for(int i =  0; i < n; i++) {
		if(s[i] == 'B') {
			cnt++;
		}
		else {
			if(cnt > 0 )
				ans.pb(cnt);
			cnt = 0;
		}
	}	
	if(cnt > 0) ans.pb(cnt);
	if(ans.size() == 0) {
		cout << 0 << endl;
		return 0;
	}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size() ; i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}