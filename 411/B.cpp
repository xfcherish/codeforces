#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <string>

using namespace std;

# define pb push_back
# define mp make_pair

typedef long long ll;
typedef pair<int,int> PII;

const int maxn =  (1e5)+10;


int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		if(i % 4 == 0 || i % 4 == 1) cout << "a";
		else cout << "b";
	}
	cout << endl;
	return 0;
}