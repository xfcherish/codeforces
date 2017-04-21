#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

# define pb push_back
# define mp make_pair

typedef long long LL;
typedef pair<int,int> PII;

const int maxn =  200010;

int a,m;
long long b, q, l;
set<int> s;

int main()
{
	cin >> b >> q >> l >> m;
	for(int i = 1; i <= m; i++) {
		cin >> a;
		s.insert(a);
	}
	if(abs(b) > l) {
		cout << 0 << endl;
	}
	else if(q == 1) {
		if(s.find(b) == s.end())
			cout << "inf" << endl;
		else 
			cout << 0 << endl;
	}
	else if(q == -1) {
		if(s.find(b) == s.end() || s.find(-b) == s.end()) {
			cout << "inf" << endl;
		}
		else cout << 0 << endl;
	}
	else if(b == 0) {
		if(s.find(0) == s.end())
			cout << "inf" << endl;
		else cout << 0 << endl;
	}
	else if(q == 0) {
		if(s.find(0) == s.end()) 
			cout << "inf" << endl;
		else {
			if(s.find(b) == s.end()) 
				cout << 1 << endl;
			else cout << 0 << endl;
		}

	}
	else {
		int cnt = 0;
		while(abs(b) <= abs(l)) {
			if(s.find(b) == s.end())
				cnt++;
			b = b*q;
		}
		cout << cnt << endl;
	}
	return 0;
}