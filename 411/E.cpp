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
	int l,r,max = 0, sub, save = 0;
	cin >> l >> r;
	for(int i = 2; i <= l; i++) {
		sub = (r-l)/i;
		if(r % i == 0) sub += 1;
		if(sub >= max) {
			max = sub;
			save = i;
		}
		else if(max > sub) break;
	}
	cout << save << endl;
	return 0;
}