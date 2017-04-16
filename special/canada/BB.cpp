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

long long n;

int tran(char c) {
	if(c == 'f') return 1;
	if(c == 'e') return 2;
	if(c == 'd') return 3;
	if(c >= 'a' && c <= 'c')
		return (4+c-'a');
	return 0;
}

int main()
{
	char c;
	cin >> n >> c;
	n = n - 1;
	long long t = 0;
	t += (n/4)*(12+4);
	n %= 4;
	if(n == 1 || n == 3) t+= (6+1);
	t += tran(c);
	cout << t << endl;
	return 0;
}