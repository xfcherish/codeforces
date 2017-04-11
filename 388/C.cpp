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

int n;
string s;
bool vis[maxn];

int main()
{
	cin >> n >> s;
	int D,R;
	D = R = 0;
	memset(vis, 1, sizeof(vis));
	for(int i = 0; i < n; i++) {
		if(s[i] == 'D') D++;
		else R++;
	}
	int k1,k2;
	k1 = k2 = 0;
	for(int i = 0;  ; i = (i+1)%n) {
		if(vis[i] == 1) {
			if(s[i] == 'D') {
				if(R == 0) {
					cout << "D" << endl;
					return 0;
				}
				while(1) {
					if(s[k2] == 'R' && vis[k2] == 1) break;
					k2 = (k2+1) % n;
				}
				R--;
				vis[k2] = 0;
				cout << "ban " << k2 << " R" << endl;
				k2 = (k2+1) % n;
				if(R == 0) {
					cout << "D" << endl;
					return 0;
				}
			}
			else {
				if(D == 0) {
					cout << "R" << endl;
					return 0;
				}
				while(1) {
					if(s[k1] == 'D' && vis[k1] == 1) break;
					k1 = (k1+1) % n;
				}
				D--;
				vis[k1] = 0;
				cout << "ban " << k1 << " D" << endl;
				k1 = (k1+1) % n;
				if(D == 0) {
					cout << "R" << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}