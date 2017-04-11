#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int a[105],n;
bool vis[105];

int find(int num) {
	for(int i = 1; i <= n; i++) 
		if(vis[i] == 0 && a[i] == num)
			return i;
	return -1;
}

int main()
{
	int i;
	cin >> n;
	int sum = 0;
	for(i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	int half = n/2;
	int each_sum = sum/half;
	memset(vis,0,sizeof(vis));
	for(int i = 1; i <= n; i++) {
		if(vis[i] == 0) {
			vis[i] = 1;
			int j = find(each_sum - a[i]);
			cout << i << " " << j << endl;
			vis[j] = 1 ;
		}
	}
	return 0;
}