#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> v;
int main()
{
	int n;
	string s;
	cin >> n;
	bool tag = false;
	for(int i = 0; i < n; i++) {
		cin >> s;
		if(tag == false) {
			if(s[0] == 'O' && s[1] == 'O') {
				s[0] = '+';
				s[1] = '+';
				tag = true;
			}
			else if(s[3] == 'O' && s[4] == 'O'){
				s[3] = '+';
				s[4] = '+';
				tag = true;
			}
		}
		v.push_back(s);
	}
	if(tag == false) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		for(int i = 0; i < n; i++)
			cout << v[i] << endl;
	}
	return 0;
}