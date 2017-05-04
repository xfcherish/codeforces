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

const int maxn =  (1e5)+10;

bool judge(string s, int pos) {
	int i = 0, j = s.length()-1;
	while(i <= j) {
		if(i == pos || j == pos) {
			int other = i + j - pos;
			if(pos != other && s[pos] == s[other]) return false;
			i++;
			j--;
			continue;
		}
		if(s[i] != s[j]) return false;
		i++;
		j--;
		// cout << "i = " << i << " j = " << j << endl;
	}
	return true;
}

int main()
{
	string a;
	cin >> a;
	for(int i = 0; i < a.length(); i++) {
		if(judge(a,i)) {
			cout << "YES" << endl;
			return 0;
		}
	}	
	cout << "NO" << endl;
	return 0;
}