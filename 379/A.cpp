#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int maxn = (1e5)+10;

int n;
string s;
int main()
{
	cin >> n >> s;
	int cnt1,cnt2;
	cnt1 = cnt2 = 0;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == 'A') cnt1++;
		if(s[i] == 'D') cnt2++;
	}
	if(cnt1 > cnt2) cout << "Anton" << endl;
	else if(cnt1 < cnt2) cout << "Danik" << endl;
	else cout << "Friendship" << endl;
	return 0;
}