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

string s;
int n,a,b,k;
struct one {
	int start,last,d;
	one(int _start, int _end, int _d) {
		start = _start;
		last = _end;
		d = _d;
	}
};
vector<one> v;
vector<int> pos,ans;

bool cmp(const one & s1, const one & s2) {
	return s1.d < s2.d;
}

int main()
{
	cin >> n >> a >> b >> k;
	cin >> s;
	s = '1' + s + '1';
	for(int i = 0; i < s.length(); i++) 
		if(s[i] == '1') pos.push_back(i);
	for(int i = 0; i+1 < pos.size(); i++) 
		v.push_back(one(pos[i],pos[i+1],pos[i+1]-pos[i]));
	sort(v.begin(), v.end(), cmp);
	int cap = 0;
	for(int i = 0; i < v.size(); i++) {
		int d = v[i].last - v[i].start - 1;
		cap += (d/b);
	}
	for(int i = 0; i < v.size(); i++) {
		int d = v[i].last - v[i].start - 1;
		int max_n = d/b;
		if(max_n == 0) continue;
		// cout << "cap = " << cap << endl;
		// cout<< "max_n = " << max_n << endl;
		if(cap - max_n >= a) {
			int cnt = 0;
			for(int j = v[i].start+1; j < v[i].last ; j++) {
				cnt++;
				if(cnt == b) {
				//	cout << "j = " << j << endl;
					ans.push_back(j);
					cnt = 0;
				}
			}
			cap -= max_n;
		}
		else {
			int min_n = a - (cap-max_n);
			// cout << "min_n = " << min_n << endl;
			int len = min_n*b;
			int cnt = 0;
			for(int j = v[i].start+1; j < v[i].last ; j++) {
				cnt++;
				if(cnt == 1) ans.push_back(j);
				if(cnt == len) cnt = 0;
				
			}
			a = a - (cap-max_n);
		}
		if(a == 0) break;
	}
	cout << ans.size() << endl;
	for(int i = 0 ; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}


