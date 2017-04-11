#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;
const LL inf = (1e16);

LL check(LL m) {
	LL sum = 0;
	for(LL k = 2; k*k*k <= m ; k++) {
		sum += (m/(k*k*k));
	}
	return sum;
}

int main()
{
	LL m;
	cin >> m;
	LL  low,high,mid;
	low = 1;
	high = inf;
	LL ans;
	while(low < high) {
		mid = (low + high) / 2;
		// cout << " low = " << low << endl;
		// cout << " high = " << high << endl;
		if(check(mid)  >=  m ) 
			high = mid ;
		else low = mid + 1;
	}
	// cout << "mid = " << mid << endl;
	if(check(low) == m)
		cout << low << endl;
	else cout << -1 << endl;
	return 0;
}