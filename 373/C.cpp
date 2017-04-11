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

int n,t;
string s;

string addone(string s2) {
	// cout << "hello " << endl;
	// cout << "Inter  = " << s2 << endl;
	int len = s2.length();
	for(int i = len-1; i >= 0; ) {
		if(s2[i] != '9') {
			s2[i]++;
			return s2;
		}
		else {
			s2[i] = '0';
			if(i > 0) i--;
			else {
				string s3 = s2;
				s2 = "1" + s3;
				break;
			}
		}
	}
	// cout << "hehe inter = " << s2 << endl;
	return s2;
}

int main()
{
	int i,j,mark,last;
	cin >> n >> t;
	cin >> s;
	int len = s.length();
	i = 0;
	string inter;
	while(s[i] != '.') {
		inter += s[i];
		i++;
	}
	i = i+1;
	bool change = false;
	for( ; i < len; i++) {
		if(s[i] >= '5') {
			mark = i;
			change = true;
			break;
		}
	}
	if(change == false) {
		cout << s << endl;
	}
	else {
		for(i = mark ; i >= 0; i--) {
			if(s[i] == '.') break;
			if(s[i] >= '5' && t > 0) {
				t--;
				last = i-1;
				if(s[i-1] != '.') 
					s[i-1] += 1;
				else{
					cout << addone(inter) << endl;
					return 0;
				}
			}
			if(t == 0) {
				break;
			}
		}
		for(int i = 0; i <= last; i++) {
			cout << s[i];
		}
		cout << endl;
	}
	return 0;
}


