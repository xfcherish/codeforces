#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>


using namespace std;

int main()
{
	int t,s,x;
	cin >> t >> s >> x;
	bool tag = false;
	if(x == t+1) tag = false;
	else if((x - t) % s == 0 )
		tag = true;
	else if((x-t-1) % s == 0)
		tag = true;
	if(x < t) tag = false;
	if(tag) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
} 