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

const int maxn =  (2e5)+10;

int n,f;
int k[maxn],l[maxn];
vector<int> t;

int main()
{
	ll ans = 0;
	cin >> n >> f;
	for(int i = 1; i <= n; i++) {
		cin >> k[i] >> l[i];
		ans += min(k[i],l[i]);
		int add = min(2*k[i],l[i]) - min(k[i],l[i]);
		t.push_back(add);
	}
	sort(t.begin(), t.end(), greater<int>()) ;
	for(int i = 0; i < f; i++) 
		ans += t[i];
	cout << ans << endl;
	return 0;
}