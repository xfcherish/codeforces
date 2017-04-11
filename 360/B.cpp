#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	cin >> s;
	cout << s ;
	reverse(s.begin(), s.end());
	cout << s << endl;
	return 0;
}