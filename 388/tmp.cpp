#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<int> s;
	for(int i = 1; i <= 5; i++)
		s.insert(i);
	s.insert(3);
	s.insert(6);
	for(set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << (*it) << endl;
	}
	s.erase(s.find(3));
	for(set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << (*it) << endl;
	}
	return 0;
}