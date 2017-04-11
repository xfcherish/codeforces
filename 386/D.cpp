#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
	long long n,a,b,k,l,s;
	cin >> n >> k >> a >> b;
	char lc,sc;
	if(a >= b) {
		l = a , s = b , lc = 'G', sc = 'B';
	}
	else {
		l = b, s = a, lc = 'B', sc = 'G';
	}
	if(l > (s+1)*k) cout << "NO" << endl;
	else {
		if(l <= k) {
			for(int i = 1; i <= l; i++) cout << lc;
			for(int i = 1; i <= s; i++) cout << sc;
			cout << endl;
		}
		else {
			int r = l - s;
			int last, t, R;
			if(r <= k) {
				t = 0;
				R = 0;
				last = r;
			}
			else {
				last = k;
				R = (r - k) % s;
				t = (r - k) / s;
			}
			for(int i = 1; i <= s; i++) {
				for(int j = 1; j <= t; j++) cout << lc;
				if(R > 0) {
					cout << lc;
					R--;
				}
				cout << lc << sc;
			}
			for(int i = 1; i <= last; i++) cout << lc;
			cout << endl;
		}
	}
	return 0;
}