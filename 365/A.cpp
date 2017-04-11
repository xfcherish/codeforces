#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int n,m,c;
	cin >> n;
	int win_m = 0;
	int win_c = 0;
	int draw = 0;
	for(int i = 1; i <= n; i++) {
		cin >> m >> c;
		if(m > c) win_m++;
		else if(m < c) win_c++;
		else draw++;
	}
	if(win_c > win_m) cout << "Chris" << endl;
	else if(win_c < win_m) cout << "Mishka" << endl;
	else cout << "Friendship is magic!^^" << endl;
	return 0;
}