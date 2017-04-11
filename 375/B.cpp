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

int n;
string s;
int main()
{
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	cin >> n >> s;
	int len = s.length();
	int maxl =  0;
	int cnt = 0;
	int tag = 0;
	int cnt_l = 0; 
	for(int i = 0; i < len; i++) {
		if((s[i] <= 'z' && s[i] >= 'a') || (s[i] <= 'Z' && s[i] >= 'A')) {
			cnt_l++;
			if(tag == 0) {
				maxl = max(maxl, cnt_l);
			}
		}
		else if(s[i] == '('){
			if(cnt_l > 0 && tag > 0) {
				cnt++;
			}
			cnt_l = 0;
			tag++;
		}
		else if(s[i] == ')') {
			if(cnt_l > 0 && tag > 0) {
				cnt++;
			}
			cnt_l = 0;
			tag--;
		}
		else if(s[i] == '_') {
			if(cnt_l > 0 && tag > 0) {
				cnt++;
			}
			cnt_l = 0;
		}
	}
	cout << maxl << " " << cnt << endl;
	return 0;
}