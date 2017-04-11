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
long long a[maxn];
int n,k,x;
struct one {
	int pos;
	long long val;
};
 struct cmp{
    bool operator() (const one & s1, const one & s2) {
        if(fabs(s1.val) != fabs(s2.val))
        	return fabs(s1.val) > fabs(s2.val);
        return s1.pos < s2.pos;
    }
};
priority_queue<one, vector<one>, cmp> que;
vector<one> ans;
bool cmp2(const one & s1, const one & s2) {
	return s1.pos < s2.pos;
}

int main()
{
	int i;
	int tag = 1;  
	int zero = 0;
	cin >> n >> k >> x;
	for(i = 1; i <= n; i++) {
		cin >> a[i];
		one tmp;
		tmp.pos = i;
		tmp.val = a[i];
		que.push(tmp);
		if(a[i] < 0) tag = tag * (-1);
		if(a[i] == 0) zero += 1;
	}
	while(k--) {
		if(zero > 0) {
			one u = que.top();
			que.pop();
			if(tag == 1) {
				u.val -= x;
				tag = -1;
			}
			else if(tag == -1) {
				u.val += x;
			}
			zero --;
			que.push(u);
		}
		else {
			if(tag == 1) {
				one u = que.top();
				que.pop();
				u.val -= x;
				if(u.val < 0) {
					tag = -1;
				}
				else if(u.val == 0) {
					zero++;
				}
				que.push(u);
			}
			else if(tag == -1) {
				one u = que.top();
				que.pop();
				if(u.val < 0) u.val -= x;
				else u.val += x;
				que.push(u);
			}
		}
	}
	while(!que.empty()) {
		one u = que.top();
		ans.push_back(u);
		que.pop();
	}
	sort(ans.begin(), ans.end(), cmp2);
	for(int i = 0; i < n; i++) {
		cout << ans[i].val << " ";
	}
	cout << endl;
	return 0;
}