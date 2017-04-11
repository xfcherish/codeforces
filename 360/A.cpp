#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n,d;
	string s;
	cin >> n >> d;
	int cnt = 0;
	int ans = 0;
	for(int i = 1 ; i <= d; i++) {
		cin >> s;
		bool can_beat = false;
		for(int j = 0; j < n; j++) {
			if(s[j] == '0')
				can_beat = true;
		}
		if(can_beat) cnt++;
		else cnt = 0;
		ans = max(ans,cnt);
	}
	cout << ans << endl;
	return 0;
}