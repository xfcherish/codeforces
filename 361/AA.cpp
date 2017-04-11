#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int up(int i)
{
	if(i <= 3 && i >= 1) return -1;
	if(i <= 9 && i >= 4) return (i-3);
	return 8;
}

int down(int i)
{
	if(i == 7 || i == 9 || i == 0)
		return -1;
	if(i == 8) 
		return 0;
	return (i+3);
}

int left(int i) {
	if(i == 1 || i == 4 || i == 7) return -1;
	if(i == 0) return -1;
	return (i-1);
}

int right(int i)
{
	if(i == 3 || i == 6 || i == 9) return -1;
	if(i == 0) return -1;
	return (i+1);
}

int move(int i,int j) {
	if(i == 0) return up(j);
	if(i == 1) return down(j);
	if(i == 2) return left(j);
	if(i == 3) return right(j);
	return -1;
}

int main()
{
	int n;
	int a[10];
	cin >> n;
	for(int i = 1 ; i <= n; i++) 
		scanf("%1d",&a[i]);
	int ans = 0;
	for(int i = 0; i < 4; i++) {
		int tmp = 1;
		for(int j = 1; j <= n; j++) {
			if(move(i,a[j]) == -1) {
				tmp = 0;
				break;
			}
		}
		if(tmp == 1) { 
			ans = 1;
			break;
		}
	}
	if(ans == 1) cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}


