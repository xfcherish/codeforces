#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <string>

using namespace std;

# define pb push_back
# define mp make_pair

typedef long long ll;
typedef pair<int,int> PII;

const int maxn =  (2e5)+10;

int n,k,sum;

int main()
{
	int a;
	cin >> n >> k;
	int m = 0;
	sum = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a;
		sum += a;
	}
	while(1) {
		double s1 = sum + m*k;
		double s2 = (n+m)*(k-0.5);
		if(s1 >= s2) break;
		m++;
	}
	cout << m << endl;
	return 0;
}