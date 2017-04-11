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
int main()
{
	cin >> n >> s;
	if(n % 4 != 0) {
		cout << "===" << endl;
	}
	else {
		int len = s.length();
		int a,g,c,t;
		a = g = c = t = 0;
		int num = n/4;
		for(int i = 0; i < len; i++) {
			if(s[i] == 'A') a++;
			if(s[i] == 'G') g++;
			if(s[i] == 'C') c++;
			if(s[i] == 'T') t++;
		}
		if(a > num || g > num || c > num || t > num) {
			cout << "===" << endl;
			return 0;
		}
		else {
			for(int i = 0; i < len; i++) {
				if(s[i] == '?') {
					if(a != num) {
						s[i] = 'A';
						a++;
					}
					else if(g != num) {
						s[i] = 'G';
						g++;
					}
					else if(c != num) {
						s[i] = 'C';
						c++;
					}
					else if(t != num) {
						s[i] = 'T';
						t++;
					}
				}
			}
			cout << s << endl;
		}
	}
	return 0;
}