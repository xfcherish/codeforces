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

string s1,s2;
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string w[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

bool judge(int num) {
	int now,nxt;
	for(int i = 0; i < 12; i++) {
		now = num;
		nxt = (now + days[i]) % 7;
		if(w[now] == s1 && w[nxt] == s2) 
			return true;
	}
	return false;
}
int main()
{
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	cin >> s1 >> s2;
	bool tag = false;
	for(int i = 0; i < 7; i++) {
		if(judge(i)) {
			tag = true;
			break;
		}	
	}
	if(tag) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}