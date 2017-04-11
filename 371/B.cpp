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

int n,a[maxn];
set<int> s;
vector<int> num;

bool judge(int x, int y) {
	for(int i = 0; i < num.size(); i++) {
		if(num[i] != y && num[i] != y+x 
			&& num[i] != y-1)
			return false;
	}
	return true;
}
int main()
{
	int i;
	cin >> n;
	for(i = 1; i <= n; i++) { 
		cin >> a[i];
		if(s.find(a[i]) == s.end())
			s.insert(a[i]);
	}
	if(s.size() > 3) 
		cout <<  "NO" << endl;
	else {
		set<int>::iterator it;
		for(it = s.begin() ; it != s.end(); it++) 
			num.push_back(*it);
		if(num.size() == 1 || num.size() == 2) {
			cout << "YES" << endl;
		}
		else {
			sort(num.begin(), num.end());
			if(num[1] == num[0] || num[1] == num[2]) {
				cout << "YES" << endl;
			}
			else {
				if(num[2]-num[1] == num[1] - num[0])
					cout << "YES" << endl;
				else cout << "NO" << endl;
			}
		}
	}
	return 0;
}