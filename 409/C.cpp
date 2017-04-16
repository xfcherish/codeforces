#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>

using namespace std;

# define pb push_back
# define mp make_pair

typedef long long LL;
typedef pair<int,int> PII;

const int maxn =  (1e5)+10;
const double eps = (1e-5);

int n,a[maxn],b[maxn];
long long p,sum;

bool judge(double mid) {
	double total = mid * p;
	for(int i = 1; i <= n; i++) {
		double need = mid*a[i] - b[i];
		if(need > 0) {
			if(need > total) 
				return false;
			else 
				total -= need;
		}	
	}
	return true;
}

int main()
{
	freopen("output.txt","r",stdin);
	sum = 0;
	cin >> n >> p;
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &a[i], &b[i]);
		sum = sum + a[i];
	}
	double high,mid,low;
	if(sum <= p) {
		cout << -1 << endl;
	}
	else {
		low = 0;
		high = (1e11)+100;
		while(high - low > eps ) {
			mid = (low + high)/2;
			// cout << "low = " << low << " high = " << high << endl;
			// cout << "mid = " << mid << " judge(mid) = " << judge(mid) << endl;
			if(judge(mid) == true) low = mid;
			else high = mid ;
		}
		cout << low << endl;
	}
	return 0;
}