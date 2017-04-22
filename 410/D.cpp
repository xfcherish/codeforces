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

const int maxn =  (1e5)+10;

int a[maxn],b[maxn],p[maxn],n;

bool cmp(const int & s1, const int & s2) {
	return a[s1] > a[s2];
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	for(int i = 1; i <= n; i++) p[i] = i;
	sort(p+1, p+1+n, cmp);
	vector<int> ans;
	ans.push_back(p[1]);
	int k = (n/2) + 1;
	for(int i = 2; i <= n; i += 2) {
		int cur = p[i];
		if(i+1 <= n && b[cur] < b[p[i+1]])
			cur = p[i+1];
		ans.push_back(cur);
	}
	cout << k << endl;
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}