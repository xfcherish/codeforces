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
string s;
int main()
{
	cin >> n >> s;
	string s2 = "";
	for(int i = 0 ; i < n; ) {
		if(s[i] != 'o') {
			s2 += s[i];
			i++;
		}
		else {
			if(i+2 >= n) {
				s2 += s[i];
				i++;
				continue;
			}
			if(s[i] == 'o' && s[i+1] == 'g' && s[i+2] == 'o') {
				int j = i+3;
				while(j+1 < n && s[j] == 'g' && s[j+1] == 'o') 
					j += 2;
				i = j;
				s2+="***";
			}
			else {
				s2 += s[i];
				i++;
			}
		}
	}
	cout << s2 << endl;
	return 0;
}