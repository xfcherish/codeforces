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

int n,k;
int t[maxn];
vector<int> num,num2;

int main()
{
	cin >> n >> k;
	int num_w = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &t[i]);
		if(t[i] < 0) {
			num_w++;
			num.push_back(i);
		} 
	}
	int ans = 2*num_w;
	if(k < num_w) {
		cout << -1 << endl;
	}
	else if(num_w == 0) {
		cout << 0 << endl;
	}
	else {
		int r = k - num_w;
		for(int i = 1; i < num.size(); i++) {
			num2.push_back(num[i]-num[i-1]-1);	
		}
		sort(num2.begin(), num2.end());
		for(int i = 0; i < num2.size(); i++) {
			if(num2[i] == -1) ans -= 2;
			if(r < num2[i]) {
				break;
			}
			else {
				r -= num2[i];
				ans -= 2;
			}
		}
		int last = n - num[num.size()-1];
		// cout << "r = " << r << " last = " << last << endl;
		if(r >= last) {
			r -= last;
			ans --;
		}
		cout << ans << endl;
	}
	return 0;
}