#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <string>


using namespace std;

int main()
{
	string s;
	cin >> s;
	int a = s[0]-'0';
	int b = 0;
	int len = s.length();
	int dot = -1;
	int e_pos = -1;
	bool start = false;
	for(int i = 0; i < len; i++) {
		if(start) {
			b *= 10;
			b += (s[i]-'0');
		}
		if(s[i] == '.') dot = i;
		if(s[i] == 'e') { 
			start = true;
			e_pos = i;
		}
	}
	s.erase(s.begin()+e_pos, s.end());
	len = s.length();
	for(int i = 0; i <= 100; i++)
		s += "0";
	for(int i = 0; i < b; i++) {
		swap(s[dot],s[dot+1]);
		dot++;
	}
	bool allzero = true;
	for(int i = 0; i < len; i++) {
		if(s[i] > '0' && s[i] <= '9') {
			allzero = false;
			break;
		}
	}
	if(allzero) {
		cout << 0 << endl;
		return 0;
	}
	int last;
	if(dot < len - 1) {
		last = len;
		while((last > 1) && ((s[last-1] == '0') || (s[last-1] == '.')))
			last--;
	}
	else last = dot;
	if(a == 0 && dot == 1) {
		for(int i = 0; i < last; i++)
			cout << s[i];
		cout << endl;
		return 0;
	}
	start = false;
	for(int i = 0; i < last; i++) {
		if(s[i] != '0') start = true;
		if(start) cout << s[i];
	}
	cout << endl;
	return 0;
}