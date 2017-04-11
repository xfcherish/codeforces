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

const int maxn = (50)+10;

char c[maxn][maxn];
bool vis[maxn][maxn],vis2[maxn][maxn];
int m,n,k;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

struct one {
	vector<PII> lake;
	int lake_size;
	one(vector<PII> _lake, int _size): lake(_lake), lake_size(_size) {}
};
vector<PII> curlake;

bool dfs(int x, int y) {
	if(x <= 0 || y <= 0) return false;
	if(x > n || y > m) return false;
	if(c[x][y] == '*') return true;
	vis[x][y] = 1;
	curlake.pb(make_pair(x,y));
	bool tag = true;
	for(int i = 0; i < 4; i++) {
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		//if(vis[new_x][new_y] == 1) continue;
		if(vis[new_x][new_y] == 0 && dfs(new_x, new_y) == false) {
			tag = false;
		}
	}
	return tag;
}


bool cmp(const one & s1, const one & s2) {
	return s1.lake_size < s2.lake_size;
}

void print() {
	cout << "cur lake size = " << curlake.size() << endl;
	for(int i = 0 ; i < curlake.size(); i++) {
		cout << curlake[i].first << " " << curlake[i].second << endl;
	}
}

int main()
{
	//freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1 ; i <= n; i++) {
		scanf("\n");
		for(int j = 1; j <= m; j++) {
			scanf("%c", & c[i][j]);
		}
	}
	memset(vis, 0, sizeof(vis));
	memset(vis2, 0, sizeof(vis2));
	vector<one> total;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(c[i][j] == '.' && vis[i][j] == 0) {
				curlake.clear();
				if(dfs(i,j)) {
					//print();
					total.push_back(one(curlake,curlake.size()));
				}
			}
		}
	}
	int ans = 0;
	sort(total.begin(), total.end(), cmp);
	int t = total.size();
	//cout << "t = " << t << endl;
	for(int i = 0; i < t-k; i++) {
		ans += total[i].lake_size;
		for(int j = 0 ; j < total[i].lake_size; j++) {
			 int new_x = total[i].lake[j].first;
			 int new_y = total[i].lake[j].second;
			 c[new_x][new_y] = '*';
		}
	}
	cout << ans << endl;
	for(int i = 1;  i <= n; i++) {
		for(int j = 1;  j <= m; j++) {
			printf("%c",c[i][j]);
		}
		cout << endl;
	}
	return 0;
}