#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int maxn = 510;
long long a[maxn][maxn],sum;
int n;

bool judge()
{
	for(int i = 1; i <= n; i++) {
		long long tmp = 0;
		for(int j = 1; j <= n; j++) {
			tmp += a[i][j];
		}
		if(tmp != sum) return false;
	}
	for(int i = 1; i <= n; i++) {
		long long tmp = 0;
		for(int j = 1; j <= n; j++) {
			tmp += a[j][i];
		}
		if(tmp != sum) return false;
	}
	long long tmp = 0;
	for(int i = 1; i <= n; i++)
		tmp += a[i][i];
	if(tmp != sum) return false;
	tmp = 0;
	for(int i = 1; i <= n; i++)
		tmp += a[i][n+1-i];
	if(tmp != sum) return false;
	return true;
}
int main()
{
	int i,j;
	cin >> n;
	int pos_i, pos_j;
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= n; j++) {
			cin >> a[i][j];
			if(a[i][j] == 0) {
				pos_i = i;
				pos_j = j;
			}
		}
	}
	sum = 0;
	if(pos_i == 1) {
		for(i = 1; i <= n; i++)
			sum += a[2][i];
	}
	else {
		for(i = 1; i <= n; i++)
			sum += a[1][i];
	}
	long long value = sum;
	for(i = 1; i <= n; i++) 
		value -= a[pos_i][i];
	a[pos_i][pos_j] = value;
	if(n == 1) {
		cout << 1 << endl;
		return 0;
	}
	if(judge() && value > 0) cout << value << endl;
	else cout << -1 << endl;
	return 0;
}