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

const int maxn = 600000;
int cnt[maxn],n;

int main()
{
	//freopen("input.txt","r",stdin);
	string type,s;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> type >> s;
		if(type == "+" || type == "-") {
			int add = 0;
			int high_even = 0;
			for(int j = 0; j < s.length(); j++) {
				int num = s[j] - '0';
				if(num % 2 == 1) {
					high_even = j;
					break;
				}
			}
			int digit = 1;
			for(int j = s.length()-1; j >= high_even; j--) {
				int num = (s[j]-'0');
				if(num % 2 == 1) {
					add += digit;
				}
				digit *= 2;
			}
			// cout << "s = " << s << endl;
			// cout << type << "num = " << add << endl;
			if(type == "+") cnt[add]++;
			else cnt[add]--;
		}
		else if(type == "?") {
			int add = 0;
			int high_even = 0;
			for(int j = 0; j < s.length(); j++) {
				int num = s[j] - '0';
				if(num % 2 == 1) {
					high_even = j;
					break;
				}
			}
			int digit = 1;
			for(int j = s.length()-1; j >= high_even; j--) {
				add += (s[j]-'0')*digit;
				digit *= 2;
			}
			// cout << "query num = " << add << endl;
			cout << cnt[add] << endl;
		}
	}
	return 0;
}