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

int n;
int a[100];
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	if(a[n] == 0) { 
		cout << "UP" << endl;
		return 0;
	}
	else if(a[n] == 15) { 
		cout << "DOWN" << endl; 
		return 0;
	}
	if(n == 1) cout << -1 << endl;
	else if(n >= 2) {
		if(a[n] > a[n-1]) cout << "UP" << endl;
		else cout << "DOWN" << endl;
	}
	return 0;
}