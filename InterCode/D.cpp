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

const int maxn = (5e4)+10;
int a[maxn],b[maxn],n;

set<int> s;

bool judge(int max_num) {
	s.clear();
	for(int i = 1; i <= n; i++) 
		b[i] = a[i];
	for(int i = 1; i <= n; i++) {
		while(b[i] > max_num) 
			b[i] = b[i]/2;
		while(s.find(b[i]) != s.end()) 
			b[i] = b[i]/2;
		if(b[i] > 0) 
			s.insert(b[i]);
		else return false;
		//cout << "b[" << i << "]=" << b[i] << endl;
	}
	return true;;
}

int main()
{
	int low,high;
	cin >> n;
	low = high = n;
	for(int i = 1; i <= n; i++)  {
		cin >> a[i];
		high = max(high, a[i]);
	}
	while(low < high) {
		int mid = (low+high)/2;
		if(judge(mid)) 
			high = mid;
		else low = mid+1;
	}
	//cout << judge(low) << endl;
	judge(low);
	for(int i = 1; i <= n; i++)
		cout << b[i] << " ";
	cout << endl;
	return 0;
}