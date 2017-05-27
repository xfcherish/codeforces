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

const int maxn =  (2e5)+10;



int main()
{
	int a,b;
	cin >> a >> b;
	ll sum_a,sum_b;
	sum_a = sum_b = 0;
	for(int i = 1;   ; i++) {
		if(i % 2 == 1) {
			sum_a += i;
			if(sum_a > a) {
				cout << "Vladik" << endl;
				return 0;
			}
		}
		else {
			sum_b += i;
			if(sum_b > b) {
				cout << "Valera" << endl; 
				return 0;
			}
		}
	}
	return 0;
}