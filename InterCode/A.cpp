#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

#define pb push_back
#define mp make_pair

typedef long long LL;
typedef pair<int,int> PII;

const int maxn = (1e5)+10;

int main()
{
	int tag,hh,mm;
	char c;
	cin >> tag;
	cin >> hh >> c >> mm;
	if(mm >= 60)
		mm -= 60;
	if(tag == 24) {
		if(hh > 23) {
			hh %= 10;
		}
	}
	else if(tag == 12){
		if(hh == 0)
			hh += 1;
		else if(hh > 12) {
			if(hh % 10 != 0) {
				hh = hh % 10;
			}
			else {
				hh = 10;
			}
		}
	}
	printf("%02d:%02d\n",hh,mm);
	return 0;
}