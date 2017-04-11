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

vector<string> v;
string s;

int cal(int times, int k) {
	int ans = 0;
	int cnt = 0;
	for(int i = 1; i < times; i++) {
		ans++;
		cnt++;
		if(cnt == k) {
			ans += 5;
			cnt = 0;
		}
	}
	return ans+1;
}

int main()
{
	int n,k;
	string temp;
	cin >> n >> k;
	for(int i = 0 ; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	cin >> s;
	int less_cnt = 0;
	int lequal_cnt = 0;
	for(int i = 0 ; i < v.size(); i++) {
		if(v[i].length() < s.length()) less_cnt++;
		if(v[i].length() <= s.length()) lequal_cnt++;
	}
//	cout << "less_cnt = " << less_cnt << endl;
	int best_case = cal(less_cnt+1,k);
	int worst_case = cal(lequal_cnt,k);
	cout << best_case << " " << worst_case << endl;
	return 0;
}