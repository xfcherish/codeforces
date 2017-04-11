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

const int maxn = 500+10;

int n,m;
vector<string> matrix;
int lx,ly,rx,ry;

bool judge() {
	for(int i = lx; i <= rx; i++) {
		for(int j = ly; j <= ry; j++) {
			if(matrix[i][j] == '.') return false;
		}
	}
	return true;
}

int main()
{
	cin >> n >> m;
	string tmp;
	for(int i = 0; i < n; i++) {
		cin >> tmp;
		matrix.push_back(tmp);
	}
	lx = ly = 100000;
	rx = ry = -1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(matrix[i][j] == 'X') {
				lx = min(lx,i);
				ly = min(ly,j);
				rx = max(rx,i);
				ry = max(ry,j);
			}
		}
	}
	if(judge()) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}