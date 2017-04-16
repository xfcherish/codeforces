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

int countS(string s) {
	int cnt = 0;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == 'V') {
			if(i+1 < s.length()) {
				if(s[i+1] == 'K')
					cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
	freopen("output.txt","w",stdout);
	int n = 100000;
	int p = n-1;
	cout << n <<  " " << p <<  endl;
	for(int i = 1; i <= n; i++) {
		cout << 1<< " " << 100000 << endl;
	}
	return 0;
}