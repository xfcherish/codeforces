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

bool judge(char c) {
	if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || 
		c == 'U' || c == 'Y')
		return 1;
	return 0;
}
string s;
int main()
{
	cin >> s;
	int step = 1;
	int last = 0;
	for(int i = 0 ; i < s.length(); i++) {
		if(judge(s[i])) {
			step = max(step, (i+1)-last);
			last = i+1;
		}
	}
	int n = s.length();
	step = max(step, n+1-last);
	cout << step <<  endl;
	return 0;
}