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

int main()
{
	int n,n2;
	cin >> n;
	if(n % 2 == 0) {
		n2 = n/2;
		cout << n2 << endl;
		for(int i = 1; i <= n2; i++)
			cout << "2 ";
		cout << endl;
	}
	else {
		n = n - 3;
		n2 = n/2 + 1;
		cout << n2 << endl;
		cout << "3 ";
		for(int i = 1; i < n2; i++)
			cout << "2 ";
		cout << endl;
	}
	return 0;
}