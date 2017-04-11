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

const int maxn =  200010;

int n,k;
int a[100];
bool judge[100];
string str[100];

void init() {
	for(int i = 1; i <= 50; i++) {
		if(i <= 26) {
			str[i] = "A";
			str[i] += (char)('a'+i-1);
		}
		else {
			str[i] = "Aa";
			str[i] += (char)('a'+i-26);
		}
	}
}

int main()
{
	init();
	string s;
	cin >> n >> k;
	int cnt = 1;
	memset(judge, 0, sizeof(judge));
	for(int i = 1; i <= n-k+1; i++) {
		cin >> s;
		if(s == "YES") 
			judge[i] = 1;
	}
	for(int i = 1; i <= n; i++) a[i] = i;
	for(int i = 1; i <= n-k+1; i++) {
		if(judge[i] == 0) {
			a[i+k-1] = a[i];
		}
	}
	for(int i = 1; i <= n; i++) {
		// cout << a[i] << endl;
		cout << str[a[i]] << " ";
	}
	cout << endl;
	return 0;
}