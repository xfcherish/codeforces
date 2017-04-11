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

int main()
{
	int a,b;
	cin >> a >> b;
	int y = 0;
	while(a <= b) {
		a *= 3;
		b *= 2;
		y++;
	}
	cout << y << endl;
	return 0;
}