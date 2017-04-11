#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>

using namespace std;

# define pb push_back
# define mp make_pair

typedef long long LL;
typedef pair<int,int> PII;

const int maxn =  1000010;

int n,m,k,u,v;
int h[maxn];


int main()
{
	memset(h, 0 , sizeof(h));
	cin >> n >> m >> k;	
	for(int i = 1; i <= m; i++) {
		scanf("%d", &u);
		h[u] = 1;
	}
	int now = 1;
	int tag = 0;
	for(int i = 1; i <= k; i++) {
		scanf("%d%d", &u, &v);
		// cout << "now = " << now << endl;
		if(tag == 1) continue;
		if(now != u && now != v) continue;
		else if(now == u) {
			now = v;
			if(h[now] == 1) {
				tag = 1; 
			}
		}
		else if(now == v) {
			now = u;
			if(h[now] == 1) {
				tag = 1;
			}
		}
	}
	if(h[1] == 1) {
		cout << 1 << endl;
		return 0;
	}
	cout << now << endl;
	return 0;
}