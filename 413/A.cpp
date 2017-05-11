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

int n,t,k,d;
int main()
{
	int ans1,ans2;
	cin >> n >> t >> k >> d;
	int now = 0;
	for(int i = 1; i <= 10000000; i++) {
		if(i % t == 0) {
			now += k;
		}
		if(now >= n) {
			ans1 = i;
			break;
		}
	}
	now = 0;
	for(int i = 1; i <= 10000000; i++) {
		if(i % t == 0) now += k;
		if(i > d) {
			if((i-d) % t == 0)
				now += k;
		} 
		if(now >= n) {
			ans2 = i;
			break;
		}
	}
	if(ans2 < ans1) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}