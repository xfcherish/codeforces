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

char c[3][15];
bool vis[26];
string s;

void move() {
	char temp[3][15];
	for(int i = 1; i <= 2; i++) {
		for(int j = 1; j <= 13; j++) {
			temp[i][j] = c[i][j];
		}
	}
	c[1][1] = temp[2][1];
	for(int i = 2; i <= 13; i++)
		c[1][i] = temp[1][i-1];
	c[2][13] = temp[1][13];
	for(int i = 1; i <= 12; i++) 
		c[2][i] = temp[2][i+1];
}

int main()
{
	//freopen("input.txt","r",stdin);
	cin >> s;
	char dup_letter;
	int pos1, pos2;
	int len = s.length();
	for(int i = 0; i < len; i++) {
		int cur = s[i]-'A';
		if(vis[cur] == 1) dup_letter = s[i];
		if(vis[cur] == 0) vis[cur] = 1;
	}
	pos1 = pos2 = -1;
	for(int i = 0; i < len; i++) {
		if(s[i] == dup_letter) {
			if(pos1 == -1) pos1 = i;
			else if(pos2 == -1) pos2 = i;
		}
	}
	// cout << "dup_letter = " << dup_letter << endl;
	// cout << "pos1 = " << pos1 << " pos2 = " << pos2 << endl;
	int cnt = 0;
	int row = 1;
	int tag = 1;
	for(int i = 0; i < len; i++) {
		if(i == pos2) continue;
		cnt = cnt + tag;
		if(cnt > 13 ) {
			cnt = 13;
			tag = -1;
			row = 2;
		}
		c[row][cnt] = s[i];
	}
	// cout << "initial" << endl;
	// for(int i = 1; i <= 2; i++) {
	// 	for(int j = 1; j <= 13; j++) {
	// 		cout << c[i][j];
	// 	}
	// 	cout << endl;
	// }
	int d = pos2 - pos1 - 1;
	if(d == 0) {
		cout << "Impossible" << endl;
		return 0;
	}
	int start = 13 - d/2;
	//cout << "start = " << start << endl;
	while(c[1][start] != dup_letter) {
		move();
	}
	for(int i = 1; i <= 2; i++) {
		for(int j = 1; j <= 13; j++) {
			cout << c[i][j];
		}
		cout << endl;
	}
	return 0;
}