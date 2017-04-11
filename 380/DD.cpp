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
vector<PII> v;
vector<int> pos;

int main()
{
	cin >> n >> a >> b >> k;
	cin >> s;
	s = '1' + s + '1';
	for(int i = 0; i < s.length(); i++) 
		if(s[i] == '1') pos.push_back(i);
	for(int i = 0; i+1 < pos.size(); i++) 
		v.push_back(make_pair(pos[i],pos[i+1]));
	vector<int> ans;
	for(int i = 0; i < v.size(); i++) {
		int start = v[i].first;
		int end = v[i].second;
		int nxt = start + b;
		//cout << "start = " << start << " nxt = " << nxt << endl;
		while(nxt < end) {
			ans.push_back(nxt);
			nxt += b;
		}
	}
	int num = ans.size() - a + 1;
	num = max(num, 0);
	cout << num << endl;
	if(num) {
		for(int i = 0 ; i < num; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}




