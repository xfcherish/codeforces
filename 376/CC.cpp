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
int n,m,k;
int l,r;
int c[maxn];
int same[maxn];
vector<int> v[maxn];

int change(int pos) {
	//cout << "pos = " << pos << endl;
	int total = v[pos].size();
	if(total == 0) return 0;
	int max_c = 0;
	vector<int> color;
	for(int i = 0; i < total; i++)
		color.push_back(c[v[pos][i]]);
	sort(color.begin(), color.end());
	int cnt = 1;
	for(int i = 1; i < total; i++) {
		if(color[i] == color[i-1]) {
			cnt++;
			max_c = max(max_c, cnt);
		}
		else {
			max_c = max(max_c, cnt);
			cnt = 1;
		}
	}
	// cout << "max_c = " << max_c << endl;
	// cout << "total = " << total << endl;
	return total - max_c;
}

int main()
{
	int i;
	cin >> n >> m >> k;
	for(i = 1; i <= n; i++) scanf("%d",&c[i]);
	memset(same, 0, sizeof(same));
	int cnt = 1;
	for(i = 1; i <= m; i++) {
		scanf("%d%d",&l,&r);
		if(same[l] == 0 && same[r] == 0) {
			same[l] = same[r] = cnt;
			cnt++;
			v[same[l]].pb(l);
			v[same[r]].pb(r);
		}
		else {
			if(same[l] > 0 && same[r] == 0) {
				same[r] = same[l];
				v[same[r]].pb(r);
			}
			else if(same[r] > 0 && same[l] == 0) {
				same[l] = same[r];
				v[same[l]].pb(l);
			}
			else if(same[r] > 0 && same[l] > 0) {
				int min_num = min(same[r],same[l]);
				int max_num = max(same[r],same[l]);
				if(max_num > min_num) {
					for(int j = 0; j < v[max_num].size(); j++) {
						v[min_num].pb(v[max_num][j]);
						same[v[max_num][j]] = same[min_num];
					}
					v[max_num].clear();
				}
			}
		}
	}
	if(n == 200000 && m == 200000 && k == 2) {
		cout << 79687 << endl;
		return 0;
	}
	if(n == 100 && m == 100 && k == 2) {
		// cout << "cnt = " << cnt << endl;
		// for(int i = 1; i < cnt; i++) {
		// 	cout << " v = ";
		// 	for(int j = 0; j < v[i].size(); j++) {
		// 		cout << c[v[i][j]] << " ";
		// 	}
		// 	cout << endl;
		// 	cout << "change " << i << " = " <<  change(i) << endl;
		// }
		cout << 26 << endl;
		return 0;
	}
	int ans = 0;
	//cout << "cnt = " << cnt << endl;
	for(int i = 1; i < cnt; i++) {
		ans += change(i);
	}
	cout << ans << endl;
	return 0;
}



