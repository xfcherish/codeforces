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

string s;
int vis[26];
char c[3][30];

int main()
{
	cin >> s;
	int n = s.length();
	char dup;
	for(int i = 0;  i < n; i++) {
		int ii = s[i]-'A';
		if(vis[ii] == 1) dup = s[i];
		if(vis[ii] == 0) vis[ii] = 1;
	}
	int pos1,pos2,start;
	pos1 = pos2 = -1;
	for(int i = 0; i < n; i++) {
		if(s[i] == dup) {
			if(pos1 == -1) pos1 = i;
			else pos2 = i;
		}
	}
	//cout << "pos1 = " << pos1 << " pos2 = " << pos2 << endl;
	int d = pos2 - pos1 - 1;
	if(d == 0) {
		cout << "Impossible" << endl;
		return 0;
	}
	else start = 13 - (d/2);
	int row = 1;
	int col = start;
	bool begin = false;
//	cout << "start = " << start << endl;
	for(int i = pos1 ; i != pos1 || (begin == false) ; i = (i+1)%n ) {
		begin = true;
		if(i == pos2) continue;
		c[row][col] = s[i];
		if(row == 1 && col < 13) col++;
		else if(row == 1 && col == 13) row = 2;
		else if(row == 2 && col > 1) col--;
		else if(row == 2 && col == 1) row = 1;
	}
	for(int i = 1; i <= 2; i++) {
		for(int j = 1; j <= 13; j++) {
			cout << c[i][j];
		}
		cout << endl;
	}
	return 0;
}

