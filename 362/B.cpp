#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <string>


using namespace std;

int main()
{
	string s,a,c;
	int b;
	cin >> s;
	if(s == "0.0e0") {
		cout << 0 << endl;
		return 0;
	}
	bool tag_a = true;
	bool tag_b = false;
	b = 0;
	for(int i = 0 ; i < s.length(); i++) {
		if(s[i] == 'e') {
			tag_a = false;
			tag_b = true;
			continue;
		}
		if(tag_a) a += s[i];
		if(tag_b) {
			b *= 10;
			b += (s[i]-'0');
		}
	}
	// cout << a << " " << b << endl;
	int cnt = b;
	for(int i = 0; i < a.length(); i++) {
		if(a[i] == '.') {
			int pos = i;
			while(cnt > 0) {
				if(pos == a.length()-1) {
					if(a[pos] == '.') {
						a[pos] = '0';
					}
					else { 
						a = a + '0';
						pos++;
					}
				}
				else {
					swap(a[pos],a[pos+1]);
					pos++;
				}
				cnt--;
			}
			break;
		}
	}
	for(int i = 0; i < a.length(); i++) {
		if(i == a.length()-1)
			if(a[i] == '.')
				break;
		c += a[i];
	}
	bool start = false;
	bool move = false;
	if(c[0] == '0') {
		if(c.length() > 1) {
			if(c[1] != '.')
				move = true; 
		}
	}
	// cout << " c = " << c << endl;
	if(move) {
		string ans;
		for(int i = 0; i < c.length(); i++) {
			if(c[i] != '0') {
				start = true;
			}
			if(start) ans += c[i];
		}
		if(ans[0] == '.') {
			cout << "0" << ans << endl;
		}
		else cout << ans << endl;
	}
	else cout << c << endl; 
	return 0;
} 