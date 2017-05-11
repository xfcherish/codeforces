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

const int maxn =  (1e5)+100;

struct one{
	int b;
	int p;
	one(int _b, int _p) {
		b = _b;
		p = _p;
	}
};

bool cmp(const one & s1, const one & s2) {
	return s1.p < s2.p;
}
vector<one> v1,v2;
int a1[maxn],a2[maxn];

int main()
{
	int b,p,c,d,n;
	string str;
	cin >> n >> c >> d;
	for(int i = 1 ; i <= n; i++) {
		cin >> b >> p >> str;
		if(str == "C") {
			v1.push_back(one(b,p));
		}
		else if(str == "D") {
			v2.push_back(one(b,p));
		}
	}
	sort(v1.begin(), v1.end(), cmp);
	sort(v2.begin(), v2.end(), cmp);
	memset(a1,0,sizeof(a1));
	memset(a2,0,sizeof(a2));
	int max_b = 0;
	for(int i = 0; i < v1.size(); i++) {
		max_b = max(max_b, v1[i].b);
		a1[v1[i].p] = max_b; 
	}
	max_b = 0;
	for(int i = 0; i < v2.size(); i++) {
		max_b = max(max_b, v2[i].b);
		a2[v2[i].p] = max_b;
	}
	for(int i = 1; i <= 100000; i++) {
		a1[i] = max(a1[i],a1[i-1]);
		a2[i] = max(a2[i],a2[i-1]);
	}
	int ans1 = a1[c];
	int ans2 = a2[d];
	// cout << "ans1 = " << ans1 << endl;
	// cout << "ans2 = " << ans2 << endl;
	int ans3 = 0;
	for(int i = 0; i < v1.size(); i++) {
		int cur = v1[i].p;
		if(cur <= c)
			ans3 = max(ans3, a1[cur] + a1[c-cur]);
	}
	for(int i = 0; i < v2.size(); i++) {
		int cur = v2[i].p;
		if(cur <= d) 
			ans3 = max(ans3, a2[cur] + a2[d-cur]);
	}
	cout << max(ans1+ans2, ans3) << endl;
	return 0;
}