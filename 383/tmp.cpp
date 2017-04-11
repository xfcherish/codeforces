#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool cmp(const string & s1, const string & s2) {
	if(s1.length() != s2.length()) 
		return s1.length() < s2.length();
	return s1<s2;
}

int main()
{
	int n;
	string s;
	while(cin >> n && n) {
		vector<string> numbers;
		while(n--) {
			cin >> s;
			numbers.push_back(s);
		}
		sort(numbers.begin(), numbers.end(), cmp);
		for(int i = 0; i < numbers.size(); i++) 
			cout << numbers[i] << endl;
		cout << endl;
	}
	return 0;
}