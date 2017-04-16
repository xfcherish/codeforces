#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>

using namespace std;

# define pb push_back
# define mp make_pair

typedef long long LL;
typedef pair<int,int> PII;

const int maxn =  105;

string solve(string s1, string s2) {
	string s;
	for(int i = 0; i < s1.length(); i++) {
		if(s1[i] >= s2[i]) {
			s += s2[i];
		}
		else {
			return "-1";
		}
	}
	return s;
}

int main()
{
	string s1,s2;
	cin >> s1 >> s2;
	cout << solve(s1,s2) << endl;;	
	return 0;
}