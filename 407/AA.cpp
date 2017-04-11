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

int n,k,a;

int main()
{
	cin >> n >> k;
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a;
		cnt += (a-1)/k + 1; 	
	}
	cout << (cnt-1)/2 + 1 << endl;
	return 0;
}