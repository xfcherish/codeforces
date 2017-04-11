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

string s;
int main()
{
	int num = 0;
	cin >> s;
	int cur = 0;
	for(int i = 0; i < s.length(); i++) {
		int cur2 = s[i]-'a';
		int add = min(abs(cur2-cur), abs((26+cur)-cur2));
		add = min(add, abs((26+cur2)-cur));
		num += add;
		cur = cur2;
	}
	cout << num << endl;
	return 0;
}