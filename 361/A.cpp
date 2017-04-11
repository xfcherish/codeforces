#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int x_pos(char c)
{
	if(c >= '1' && c <= '3')
		return 1;
	if(c >= '4' && c <= '6')
		return 2;
	if(c >= '7' && c <= '9')
		return 3;
	return 4;
}

int y_pos(char c)
{
	if(c == '1' || c == '4' || c == '7')
		return 1;
	if(c == '2' || c == '5' || c == '8'
		|| c == '0')
		return 2;
	if(c == '3' || c == '6' || c == '9')
		return 3;
	return 0;
}

int main()
{
	int n;
	string s;
	int max_x,max_y,min_x,min_y;
	cin >> n;
	cin >> s;
	max_x = min_x = x_pos(s[0]);
	max_y = min_y = y_pos(s[0]);
	for(int i = 0; i < n ; i++) {
		max_y = max(max_y, y_pos(s[i]));
		min_y = min(min_y, y_pos(s[i]));
		max_x = max(max_x, x_pos(s[i]));
		min_x = min(min_x, x_pos(s[i]));
	}
	int ans = 0;
	if(max_x == 4 ) {
		if(min_x == 1)
			ans = 0;
		else 
			ans = 1;
	}
	else{
		if(max_x - min_x == 2 && max_y - min_y == 2) 
			ans = 0;
		else ans = 1;
	}
	
	if(ans == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}