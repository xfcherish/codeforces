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

int n;
string s;
long long total;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> s;
		if(s == "Tetrahedron") total += 4;
		else if(s == "Cube") total += 6;
		else if(s == "Octahedron") total += 8;
		else if(s == "Dodecahedron") total += 12;
		else total += 20;
	}
	cout << total << endl;
	return 0;
}