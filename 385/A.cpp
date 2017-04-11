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
vector<string> v;
int n;

void shift() {
	string s1 = s;
	for(int i = 1; i < n; i++) {
		s1[i] = s[i-1];
	}
	s1[0] = s[n-1];
	s = s1;
}
int main()
{
	cin >> s;
	n = s.length();
	for(int i = 0; i < n; i++) {
		bool tag = true;
		shift();
		for(int j = 0; j < v.size(); j++) {
			if(v[j] == s) {
				tag = false;
				break;
			}
		}
		if(tag) v.push_back(s);
	}
	cout << v.size() << endl;
	return 0;
}